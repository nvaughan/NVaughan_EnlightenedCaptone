package cap.nvaughan.enlightenedcompanionapp;

import android.app.Activity;
import android.support.v7.app.ActionBarActivity;
import android.support.v7.app.ActionBar;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.os.Build;
import android.widget.SeekBar;
import android.widget.TextView;

public class MainActivity extends Activity implements SeekBar.OnSeekBarChangeListener {

    private SeekBar barRed; // declare seekbar object variable
    private SeekBar barGreen; // declare seekbar object variable
    private SeekBar barBlue; // declare seekbar object variable
    // declare text label objects
    private TextView textRedValue, textGreenVlaue, textBlueValue;


    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // load the layout
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
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
        // TODO Auto-generated method stub


    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        // TODO Auto-generated method stub

    }

}