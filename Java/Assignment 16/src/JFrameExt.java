import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Set;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JFrameExt extends JFrame implements ActionListener {

	
	
	//Declare and Create GUI objects
	  private JTextField jtfMessage = new JTextField (10);
	  private JButton jbtClickMe = new JButton ("Click Me");
	  private JButton jbtClickMeToo = new JButton ("Click Me Too");
	  private JPanel jpMain = new JPanel( );
	  private int count = 0;
	 
	  
	public JFrameExt (){
		super();
		//layout object
		FlowLayout fl = new FlowLayout();
		
		//make jpmain the content pain
		jpMain.setLayout(fl);
		
		//add the gui objects to the container 
		jpMain.add(jbtClickMe);
		jpMain.add(jtfMessage);
		jpMain.add(jbtClickMeToo);
		
		 
		jpMain.setBackground(Color.black);
		
		this.setContentPane(jpMain);
		//make the text non editable 
		jtfMessage.setEditable(false);
		
		//register the object button with actionlistener 
		jbtClickMe.addActionListener(this);
		jbtClickMeToo.addActionListener(this);

		
	}
	
	
	
	
	
	//Action Event handler method.
	  //jbtClickMe and jtbClickMeToo objects will call this method when clicked.
	  public void actionPerformed (ActionEvent e)
	  {
	          //Find out which button was clicked.
	          if (e.getSource ( ) == jbtClickMe)
	          {
	          count++;
	jtfMessage.setText("Hello " + count);
	          }
	          else if (e.getSource ( ) == jbtClickMeToo)
	          {
	          count--;
	jtfMessage.setText("Hello " + count);
	 
	          }
	 
	 
	  }
	
	
	
	
}
