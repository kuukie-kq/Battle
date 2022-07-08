aux_source_directory(. DIR_RPC_SOURCE)

add_subdirectory(view)

add_library(RPC ${DIR_RPC_SOURCE})
target_link_libraries(RPC RPC_VIEW)
