//
// Created by Hanlon on 2018/1/21.
//

#include <jni.h>
#include "libyuv.h"

extern "C"
JNIEXPORT void JNICALL Java_com_cat_libyuv_YUVConvertor_scale(
        JNIEnv *env, jclass type, jbyteArray src, jint oriWidth, jint oriHeight, jint srcWidth,
        jint srcHeight, jbyteArray dst, jint dstWidth, jint dstHeight) {

    jbyte* srcData = (jbyte*)env->GetPrimitiveArrayCritical(src, 0);
    jbyte* dstData = (jbyte*)env->GetPrimitiveArrayCritical(dst, 0);

    int startRow = (oriHeight - srcHeight) / 2;
    int startCol = (oriWidth - srcWidth) / 2;

    const uint8* srcY = (const uint8*)srcData + startRow * oriWidth + startCol;
    const uint8* srcU = (const uint8*)srcData + oriWidth * oriHeight + startRow / 2 * oriWidth / 2 + startCol / 2;
    const uint8* srcV = (const uint8*)srcData + oriWidth * oriHeight * 5 / 4 + startRow / 2 * oriWidth / 2 + startCol / 2;

    uint8* dstY = (uint8*)dstData;
    uint8* dstU = dstY + dstWidth * dstHeight;
    uint8* dstV = dstU + dstWidth * dstHeight / 4;

    libyuv::I420Scale(srcY,
            oriWidth,
            srcU,
            oriWidth / 2,
    srcV,
    oriWidth / 2,
    srcWidth,
    srcHeight,
    dstY,
    dstWidth,
    dstU,
    dstWidth / 2,
    dstV,
    dstWidth / 2,
    dstWidth,
    dstHeight,
    libyuv::kFilterBilinear
    );

    env->ReleasePrimitiveArrayCritical(src, srcData, 0);
    env->ReleasePrimitiveArrayCritical(dst, dstData, 0);
}