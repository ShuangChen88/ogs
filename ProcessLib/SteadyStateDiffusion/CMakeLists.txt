append_source_files(SOURCES)

ogs_add_library(SteadyStateDiffusion ${SOURCES})

target_link_libraries(SteadyStateDiffusion PUBLIC ProcessLib
    PRIVATE ParameterLib)

include(Tests.cmake)
