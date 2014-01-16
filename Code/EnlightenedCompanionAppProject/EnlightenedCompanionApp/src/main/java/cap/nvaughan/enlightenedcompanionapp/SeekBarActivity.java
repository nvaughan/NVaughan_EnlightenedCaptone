package cap.nvaughan.enlightenedcompanionapp;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.widget.SeekBar;
import android.widget.TextView;

/**
 * Created by nvaughan on 1/15/14.
 */
public class SeekBarActivity extends SeekBar implements SeekBar.OnSeekBarChangeListener{
    private SeekBar bar;
    private TextView textProgress, textAction;

    public SeekBarActivity(Context c)
    {
        super(c);
        setOnSeekBarChangeListener(this);
        textProgress = (TextView)findViewById(R.id.textViewProgress);
        textAction = (TextView)findViewById(R.id.textViewAction);
    }


//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.fragment_main);
//        bar = (SeekBar)findViewById(R.id.seekBar1);
//        bar.setOnSeekBarChangeListener(this);
//        textProgress = (TextView)findViewById(R.id.textViewProgress);
//        textAction = (TextView)findViewById(R.id.textViewAction);
//    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
        String progress =" "+ bar.getProgress();
        textProgress.setText("The value is "+ progress);
        textAction.setText("Changing");
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
       String progress =" "+ bar.getProgress();
        textProgress.setText("The value is "+ progress);
        textAction.setText("Done");
    }
}
