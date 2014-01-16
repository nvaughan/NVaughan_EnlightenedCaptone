//package cap.nvaughan.enlightenedcompanionapp;
//
//import android.app.Activity;
//import android.os.Bundle;
//import android.widget.SeekBar;
//import android.widget.SeekBar.OnSeekBarChangeListener;
//import android.widget.TextView;
//
//class HelloWorldActivity extends Activity implements OnSeekBarChangeListener {
//    private SeekBar bar; // declare seekbar object variable
//    // declare text label objects
//    private TextView textProgress, textAction;
//
//    /**
//     * Called when the activity is first created.
//     */
//    @Override
//    public void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        // load the layout
//        setContentView(R.layout.fragment_main);
//        bar = (SeekBar) findViewById(R.id.seekBar1); // make seekbar object
//        bar.setOnSeekBarChangeListener(this); // set seekbar listener.
//        // since we are using this class as the listener the class is "this"
//
//
//        // make text label for progress value
//        textProgress = (TextView) findViewById(R.id.textViewProgress);
//        // make text label for action
//        textAction = (TextView) findViewById(R.id.textViewAction);
//
//    }
//
//    @Override
//    public void onProgressChanged(SeekBar seekBar, int progress,
//                                  boolean fromUser) {
//        // TODO Auto-generated method stub
//
//        // change progress text label with current seekbar value
//        textProgress.setText("The value is: " + progress);
//        // change action text label to changing
//        textAction.setText("changing");
//    }
//
//    @Override
//    public void onStartTrackingTouch(SeekBar seekBar) {
//        // TODO Auto-generated method stub
//        textAction.setText("starting to track touch");
//
//    }
//
//    @Override
//    public void onStopTrackingTouch(SeekBar seekBar) {
//        // TODO Auto-generated method stub
//        seekBar.setSecondaryProgress(seekBar.getProgress());
//        textAction.setText("ended tracking touch");
//    }
//
//}