FEATURE_DEF dsfl                                        \
    dsfl_type                            char(50)       \
    fme_geometry{0}                      dsfl_point     \
    fme_geometry{1}                      dsfl_line      \
    fme_geometry{2}                      dsfl_polygon   \
    fme_geometry{3}                      dsfl_arc       \
    fme_geomattr{3}.fme_primary_axis     number(31,15)  \
    fme_geomattr{3}.fme_secondary_axis   number(31,15)  \
    fme_geomattr{3}.fme_rotation         number(31,15)  \
    fme_geomattr{3}.fme_start_angle      number(31,15)  \
    fme_geomattr{3}.fme_sweep_angle      number(31,15)  \
    fme_geometry{4}                      dsfl_text      \
    fme_geometry{6}                      dsfl_ellipse   \
    fme_geomattr{6}.fme_primary_axis     number(31,15)  \
    fme_geomattr{6}.fme_secondary_axis   number(31,15)  \
    fme_geomattr{6}.fme_rotation         number(31,15)  \
    fme_geometry{7}                      dsfl_header    \
    fme_geometry{8}                      dsfl_aggregate \
    fme_geometry{9}                      dsfl_none