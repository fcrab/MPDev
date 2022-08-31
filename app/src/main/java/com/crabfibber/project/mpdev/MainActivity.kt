package com.crabfibber.project.mpdev

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.crabfibber.project.mpdev.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = getAllCodecFromJNI()
    }

    /**
     * A native method that is implemented by the 'mpdev' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun getAllCodecFromJNI(): String

    companion object {
        // Used to load the 'mpdev' library on application startup.
        init {
            System.loadLibrary("mpdev")
        }
    }
}