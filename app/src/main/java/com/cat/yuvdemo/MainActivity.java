package com.cat.yuvdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.cat.libyuv.YUVConvertor;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        new YUVConvertor();
    }


}
