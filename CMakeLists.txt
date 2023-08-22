cmake_minimum_required(VERSION 3.27)

include(FetchContent)

FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.4 # Optionally specify a commit hash, version tag or branch here
)
FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH ./Cargo.toml)

add_executable(cpp_executable src_cpp/main.cpp)
target_link_libraries(cpp_executable PUBLIC cpp_rust_binding_example)
