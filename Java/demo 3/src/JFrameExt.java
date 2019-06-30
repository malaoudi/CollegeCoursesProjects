



import java.awt.Color;
import java.awt.Frame;


import java.awt.GridLayout ;	
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.EventObject;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class JFrameExt extends JFrame implements ActionListener {
	
	//panels
	 private JPanel jpMain = new JPanel();	//jp
	 private JPanel jb1 = new JPanel();		//jp
	 private JPanel jb2 = new JPanel();
	 private JPanel jb3 = new JPanel();
	 private JPanel jb4 = new JPanel();
		 
	//constructor
		
	 //labels
	 private JLabel jlbNum1 = new JLabel("Number 1");	//JLP
	 private JTextField jtfNum1 = new JTextField(10);	//text fields
	 private JLabel jlbNum2 = new JLabel("Number 2");
	 private JTextField jtfNum2 = new JTextField(10);
	 private JLabel jlbRes = new JLabel("Result ");
	 private JTextField jtfRes = new JTextField(10);
	 
	//constructor
		public JFrameExt() {
													//GUI: title bar. and content pane,a container object
			jpMain.setBackground(Color.yellow);
			jb1.setBackground(Color.red);
			jb2.setBackground(Color.green);
			jb3.setBackground(Color.cyan);
			jb4.setBackground(Color.magenta);
		
			//this.setContentPane(jpMain);
			//add an object to panels
			jb1.add(jlbNum1);
			jb1.add(jtfNum1);
			jb2.add(jlbNum2);
			jb2.add(jtfNum2);
			jb3.add(jlbRes);
			jb3.add(jtfRes);
			jtfRes.setEditable(false);
			
			
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			
		}



	

	
	

}
	

