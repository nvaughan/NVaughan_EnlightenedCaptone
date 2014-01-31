package cap.nvaughan.enlightenedcompanionapp;

import android.app.Activity;
import android.content.Context;
import android.hardware.usb.UsbManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;


import com.hoho.android.usbserial.driver.UsbSerialDriver;
import com.hoho.android.usbserial.driver.UsbSerialProber;

import java.io.IOException;

public class MainActivity extends Activity implements SeekBar.OnSeekBarChangeListener {

    public final static String TAG = "AndroidColor";
    private SeekBar barRed; // declare seekbar object variable
    private SeekBar barGreen; // declare seekbar object variable
    private SeekBar barBlue; // declare seekbar object variable
    // declare text label objects
    private TextView textRedValue, textGreenVlaue, textBlueValue;
    UsbManager usbManager;
    UsbSerialDriver device;
    private Button b;


    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        /* load the layout */
        setContentView(R.layout.fragment_main);
        barRed = (SeekBar) findViewById(R.id.seekRedValue); // make seekbar object
        barRed.setOnSeekBarChangeListener(this); // set seekbar listener.
        // since we are using this class as the listener the class is "this"
        barGreen = (SeekBar) findViewById(R.id.seekGreenValue); // make seekbar object
        barGreen.setOnSeekBarChangeListener(this); // set seekbar listener.

        barBlue = (SeekBar) findViewById(R.id.seekBlueValue); // make seekbar object
        barBlue.setOnSeekBarChangeListener(this); // set seekbar listener.


        // make text label for progress value
        textRedValue = (TextView) findViewById(R.id.textRedValue);
        // make text label for action
        textBlueValue = (TextView) findViewById(R.id.textBlueValue);
        textGreenVlaue = (TextView) findViewById(R.id.textGreenValue);

        usbManager = (UsbManager) getSystemService(Context.USB_SERVICE);
        b = (Button) findViewById(R.id.button);
        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int bpm = (int) R.id.BPMinput;
                sendBPMToArduino(bpm);
            }
        });


    }


    @Override
    protected void onResume() {
        super.onResume();
        device = UsbSerialProber.acquire(usbManager);
        if(device == null)
        {
            Log.d(TAG,"No USB Serival Device");
        }
        else
        {
            try
            {
                device.open();
                device.setBaudRate(115200);
            }
            catch (IOException err)
            {
                try{
                    device.close();
                }
                catch(IOException err2)
                {

                }
                device = null;
                return;
            }
        }

    }

    private void sendColorToArduino(int red,int blue,int green)
    {
        byte[] dataSend = {(byte)red, (byte)green, (byte)blue, 0x0A};
        for(int i = 0; i < dataSend.length-1;i++)
        {
            if(dataSend[i] == 0x0A)
            {
                dataSend[i]= 0x0B;
            }
        }

        if(device !=null)
        {
            try{
                device.write(dataSend,500);
            }
            catch (IOException e)
            {
               // Log.e(Tag,"can't waite");
            }
        }
    }

    private void sendBPMToArduino(int BPM)
    {
        byte[] dataSend = { (byte) 1,(byte)BPM, 0x0A};
        for(int i = 0; i < dataSend.length-1;i++)
        {
            if(dataSend[i] == 0x0A)
            {
                dataSend[i]= 0x0B;
            }
        }
        if(device !=null)
        {
            try{
                device.write(dataSend,500);
            }
            catch (IOException e)
            {
                // Log.e(Tag,"can't waite");
            }
        }

    }


    @Override
    public void onProgressChanged(SeekBar seekBar, int progress,
                                  boolean fromUser) {
        // TODO Auto-generated method stub
        if(seekBar == barRed)
        // change progress text label with current seekbar value
        textRedValue.setText("Red Value: " + progress);
        else if(seekBar == barGreen)
        // change action text label to changing
        textGreenVlaue.setText("Green Value: " + progress);
        else
            textBlueValue.setText("Blue Value: " +progress);

        sendColorToArduino(barRed.getProgress(), barBlue.getProgress(), barGreen.getProgress());
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
        sendColorToArduino(barRed.getProgress(), barBlue.getProgress(), barGreen.getProgress());


    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
       sendColorToArduino(barRed.getProgress(), barBlue.getProgress(), barGreen.getProgress());

    }

}