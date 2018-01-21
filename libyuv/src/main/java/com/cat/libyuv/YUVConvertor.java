package com.cat.libyuv;

import java.nio.ByteBuffer;

/**
 * Created by Hanlon on 2018/1/19.
 */

public class YUVConvertor {

    static{
        System.loadLibrary("jni_yuv");
    }

    public YUVConvertor(){

    }

//    public static native void scale(ByteBuffer src ,
//                                    int oriWidth,
//                                    int oriHeight,
//                                    int srcWidth,
//                                    int srcHeight,
//                                    ByteBuffer dst,
//                                    int dstWidth,
//                                    int dstHeight);

    public static native void scale(byte[] src,
                                    int oriWidth,
                                    int oriHeight,
                                    int srcWidth,
                                    int srcHeight,
                                    byte[] dst,  // 调用者申请并传入
                                    int dstWidth,
                                    int dstHeight);
}
