
cmake_minimum_required(VERSION 3.4.1)

# 严格编译
add_definitions(-Werror)
add_definitions(-Wall)

# 依赖库 libyuv
set(LIBYUV_SRC_DIR ../jni/)
add_subdirectory(${LIBYUV_SRC_DIR}
                    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} # 添加外部项目文件夹(比如与本目录同级的目录) 需要显式指定二进制目录 binary_dir
                    )
include_directories( ${LIBYUV_SRC_DIR}/include/ )


# 设置库名字
set( LIB_NAME jni_yuv )


# 构建动态库 源码
add_library( ${LIB_NAME}
                SHARED
                com_cat_libyuv_YUVConvertor.cpp
                )

# 链接
target_link_libraries( 	${LIB_NAME}
						android						#NDK标准库链接
						EGL
						GLESv2
						jnigraphics
						log
						yuv                         # static yuv  not libyuv_shared.so
					)