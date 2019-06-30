import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class JFrameExt extends JFrame implements ActionListener {
	 
	
	private JLabel jlbFrom = new JLabel("From");
	private JLabel jlbTo = new JLabel ("To  ");
	private JTextField jtf1 = new JTextField(10);
	private JTextField jtf2 = new JTextField(10);
	
	private JPanel jpMain = new JPanel();
	private JPanel jpFrom = new JPanel();
	private JPanel jpTo = new JPanel();
	
	private JPanel jpOp = new JPanel();
	private JPanel jpCtoF = new JPanel();
	private JButton jbtFtoC = new JButton("F to C");
	private JButton jbtCtoF = new JButton("C to F");
	
	
	
	public JFrameExt () {
		super();
		
		GridLayout gl = new GridLayout(3,1);	
		jpMain.setLayout(gl);
		
		jpMain.add(jpFrom);
	     jpMain.add(jpTo);
	     jpMain.add(jpOp);
	     jpFrom.setBackground(Color.red);
	     jpTo.setBackground(Color.green);
	     jpOp.setBackground(Color.magenta);
		
	     this.setContentPane(jpMain);

	     jpFrom.add(jlbFrom);
	     jpFrom.add(jtf1);
	     jpTo.add(jlbTo);
	     jpTo.add(jtf2);
	     jtf2.setEditable(false);
	     jpOp.add(jbtFtoC);
	     jpOp.add(jbtCtoF);
	     
	     jbtFtoC.addActionListener(this);
	     jbtCtoF.addActionListener(this);
	     
	} 
	   //Listener method
	     public void actionPerformed(ActionEvent ev) {
	       String sFrom,sTo;
	       double dFrom, dTo;
	       sFrom = jtf1.getText().trim();
	       dFrom = Double.parseDouble(sFrom);
	      
	       if (ev.getSource()==jbtFtoC){
	          dTo = 5.0/9.0 * (dFrom - 32.0);
	          sTo = "" + dTo;
	          jtf2.setText(sTo);
	       }
	       else if (ev.getSource()==jbtCtoF){
	          dTo = (9.0/5.0 *dFrom) + 32.0;
	          sTo = "" + dTo;
	          jtf2.setText(sTo);
	       	} 
	     }
	
}
