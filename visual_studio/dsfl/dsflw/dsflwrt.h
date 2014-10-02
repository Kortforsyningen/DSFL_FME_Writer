// FME DSFL Writer
// Lars Hansen
// CDT 2002
// Contact: lh@geogr.ku.dk

// Include the parent class definition
#include <fmewrt.h>
#include <afx.h> // for CString and CStdioFile

#include "fmestring.h"

class IFMEFeature;

const FME_UInt32 kSimpleWriterId = 51020;

class IFMEObjectsService; // Forward declarations
class IFMESession;

class DSFLWriter : public IFMEWriter
{
	public:

	protected:
	FMEString writerTypeName_;
	FMEString writerKeyword_;
	CString m_DataSetName;
	CString m_TempFileName;
	CStdioFile m_Output;
	CStdioFile m_TempOutput;
	CString m_LastDSFLClass;
	CString m_LastDSFLSubClass;
	CString m_LastRotation;
	CString m_LastTextWidth;
	CString m_LastTextSize;

	// Header state
	CString m_CoordinateOrder;
	bool m_bHeaderAlreadyProcessed;
	FMEStringArray m_HeaderAttributeNames;
	FMEStringArray m_HeaderAttributeValues;

	// Bounding box support routines
	bool m_bPointProcessed; // Set to true if any points has been passed through the bbox
	double m_Xmin,m_Xmax,m_Ymin,m_Ymax,m_Zmin,m_Zmax;
	void ResetBBox();
	void ExpandBBox(double X, double Y, double Z);

	// Processing of specific feature types
	FME_MsgNum ProcessDSFLHeader(const IFMEFeature& feature);
	FME_MsgNum ProcessDSFLPoint(const IFMEFeature& feature);
	FME_MsgNum ProcessDSFLOrigin(const IFMEFeature& feature);
	FME_MsgNum ProcessDSFLLine(const IFMEFeature& feature, bool bFirstPart);
	FME_MsgNum ProcessDSFLPolygon(const IFMEFeature& feature, bool bFirstPart);
	FME_MsgNum ProcessDSFLText(const IFMEFeature& feature);
	FME_MsgNum ProcessDSFLAggregate(const IFMEFeature& feature, bool bFirstPart);
	FME_MsgNum ProcessDSFLArc(const IFMEFeature& feature);

	// Write coordinates for feature
	void WriteFeatureCoordinates(CString Intro, const IFMEFeature& feature);

	// Write header
	FME_MsgNum WriteDSFLHeader();

	// Write origin info
	FME_MsgNum WriteDSFLOriginInfo();

	// Origin Info Map
	CMapStringToString m_OriginInfo;

	// Attribute conversion
	CMapStringToString m_AttributeMap;
	void WriteAttributeValuePair(CString A,CString V);
	FME_MsgNum EmitDSFLAttributes(const IFMEFeature& feature,bool bIncludeClass);

	// Helpers for creating and deleting feature vectors
	IFMEFeatureVector* CreateFeatureVector();
	void NukeFeatureVector(IFMEFeatureVector* V);

	public:
	DSFLWriter(const char* writerTypeName,
                          const char* writerKeyword);

	virtual ~DSFLWriter();
	virtual FME_MsgNum open(const char* datasetName,const IFMEStringArray& parameters);
	virtual FME_MsgNum abort();
	virtual FME_MsgNum close();
	virtual FME_UInt32 id() const {return kSimpleWriterId;}
	virtual FME_MsgNum write(const IFMEFeature& feature);
	virtual FME_Boolean multiFileWriter() const;
 };

