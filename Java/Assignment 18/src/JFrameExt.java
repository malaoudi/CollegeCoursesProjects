
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

	 //labels
	 private JLabel jlbNum1 = new JLabel("Number 1");	//JLP
	 private JTextField jtfNum1 = new JTextField(10);	//text fields
	 private JLabel jlbNum2 = new JLabel("Number 2");
	 private JTextField jtfNum2 = new JTextField(10);
	 private JLabel jlbRes = new JLabel("Result ");
	 private JTextField jtfRes = new JTextField(10);
	 
	 //buttons
	 private JButton jbtAdd = new JButton ("Add");	//jbt
	 private JButton jbtSub = new JButton ("Sub");
	 private JButton jbtMult = new JButton ("Mult");
	 private JButton jbtDiv = new JButton ("Div");
	 private JButton jbtClear = new JButton ("Clear");
	 
	 //menues
	 private JMenuBar jmbMain = new JMenuBar();
	 private JMenu jmuOp = new JMenu ( "Operations");
	 private JMenu jmuEtc = new JMenu ( "Etc");
	 private JMenuItem jmiAdd = new JMenuItem ( "add");	
	 private JMenuItem jmiSub = new JMenuItem ( "sub");	
	 private JMenuItem jmiMult = new JMenuItem ( "mult");	
	 private JMenuItem jmiDiv = new JMenuItem ( "div");	
	 private JMenuItem jmiClear = new JMenuItem ( "clear");	



	 
	//constructor
	public JFrameExt() {
												//GUI: title bar. and content pane,a container object
		jpMain.setBackground(Color.yellow);
		jb1.setBackground(Color.red);
		jb2.setBackground(Color.green);
		jb3.setBackground(Color.cyan);
		jb4.setBackground(Color.magenta);
	
		this.setContentPane(jpMain);
				//dividing the image to several grids(rows,cloumns)
		//note: he used jp for all instead of jb. but used jbt. Jpmain
		
		GridLayout g1= new GridLayout(4,1);
		jpMain.setLayout(g1);
		jpMain.add(jb1);
		jpMain.add(jb2);
		jpMain.add(jb3);
		jpMain.add(jb4);
		
		this.setContentPane(jpMain);
		//add an object to panels
		jb1.add(jlbNum1);
		jb1.add(jtfNum1);
		jb2.add(jlbNum2);
		jb2.add(jtfNum2);
		jb3.add(jlbRes);
		jb3.add(jtfRes);
		jtfRes.setEditable(false);
		
		jb4.add(jbtAdd);	//jp4
		jb4.add(jbtSub);
		jb4.add(jbtMult);
		jb4.add(jbtDiv);
		jb4.add(jbtClear);
		
		//handle menus
		jmbMain.add(jmuOp);
		jmbMain.add(jmuEtc);
		jmuOp.add(jmiAdd);
		jmuOp.add(jmiSub);
		jmuOp.add(jmiMult);
		jmuOp.add(jmiDiv);
		//set the menu bars
		jmuEtc.add(jmiClear);
		this.setJMenuBar(jmbMain);
		
		//register with buttons and menue items. Actionlistener. registeration . The object contains the button
		jbtAdd.addActionListener(this);
		jbtSub.addActionListener(this);
		jbtMult.addActionListener(this);
		jbtDiv.addActionListener(this);
		jbtClear.addActionListener(this);

		jmiAdd.addActionListener(this);
		jmiSub.addActionListener(this);
		jmiMult.addActionListener(this);
		jmiDiv.addActionListener(this);
		jmiClear.addActionListener(this);
	
		
	}



	@Override
	public void actionPerformed(ActionEvent ev) {
		double num1=0;
		double num2=0;
		String sNum1;
		String sNum2;
		String res2;
		
		if (ev.getSource() == jbtClear) {
			jtfNum1.setText("");
			jtfNum2.setText("");
			jtfRes.setText("");
			return;
		}

		 sNum1 = jtfNum1.getText().trim();
		 sNum2 = jtfNum1.getText().trim();
		 num1 = Double.parseDouble(sNum1);
		 num2 = Double.parseDouble(sNum2);
		 double res = 0 ;
				

		 if (ev.getSource() == jbtAdd || ev.getSource() == jmiAdd) {
			res = num1 + num2;			
		}
		 
		else if (ev.getSource() == jbtSub || ev.getSource() == jmiSub) {
			res = num1 - num2;
		}
		
		else if (ev.getSource() == jbtDiv || ev.getSource() == jmiMult) {
			res = num1 * num2;
		}
		else if (ev.getSource() == jbtDiv || ev.getSource() == jmiDiv) {
			res = num1 / num2;
		}
		 
		 jtfRes.setText("" + res);
			
	}



	

	
	

}