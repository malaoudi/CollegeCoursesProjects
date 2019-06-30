import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextField;
public class JFrameExt extends JFrame implements ActionListener {
private static final long serialVersionUID = 1L;
private JPanel jpMain = new JPanel();
private JPanel jp1 = new JPanel();
private JPanel jp2 = new JPanel();
private JPanel jp3 = new JPanel();
private JPanel jp4 = new JPanel();
private JLabel jlbNum1 = new JLabel("Number1");
private JLabel jlbNum2 = new JLabel("Number 2");
private JLabel jlbRes = new JLabel("Result");
private JTextField jtfNum1 = new JTextField(10);

private JTextField jtfNum2 = new JTextField(10);
private JTextField jtfRes = new JTextField(10);
private JButton jbtAdd = new JButton("Add");
private JButton jbtSub = new JButton("Sub");
private JButton jbtMult = new JButton("Mult");
private JButton jbtDiv = new JButton("Div");
private JButton jbtC = new JButton("Clear");

private JMenuBar jmbMain = new JMenuBar();
private JMenu jmuOp = new JMenu ( "Operations");
private JMenu jmuEtc = new JMenu ( "Etc");
private JMenuItem jmiAdd = new JMenuItem ( "add");	
private JMenuItem jmiSub = new JMenuItem ( "sub");	
private JMenuItem jmiMult = new JMenuItem ( "mult");	
private JMenuItem jmiDiv = new JMenuItem ( "div");	
private JMenuItem jmiClear = new JMenuItem ( "clear");	



public JFrameExt() {
jpMain.setBackground(Color.yellow);
jp1.setBackground(Color.red);
jp2.setBackground(Color.green);
jp3.setBackground(Color.cyan);
jp4.setBackground(Color.magenta);
this.setContentPane(jpMain);
// GridLayout gl = new GridLayout(4,1);
jpMain.setLayout(new GridLayout(4,1));
jpMain.add(jp1);
jpMain.add(jp2);
jpMain.add(jp3);
jpMain.add(jp4);
this.setContentPane(jpMain);
//add object to panels
jp1.add(jlbNum1);
jp1.add(jtfNum1);
jp2.add(jlbNum2);
jp2.add(jtfNum2);
jp3.add(jlbRes);
jp3.add(jtfRes);
jtfRes.setEditable(false);
jp4.add(jbtAdd);
jp4.add(jbtSub);
jp4.add(jbtMult);
jp4.add(jbtDiv);
jp4.add(jbtC);

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
		
//register
jbtAdd.addActionListener(this);
jbtSub.addActionListener(this);
jbtMult.addActionListener(this);
jbtDiv.addActionListener(this);
jbtC.addActionListener(this);

jmiAdd.addActionListener(this);
jmiSub.addActionListener(this);
jmiMult.addActionListener(this);
jmiDiv.addActionListener(this);
jmiClear.addActionListener(this);

}
public void actionPerformed(ActionEvent ev) {
double num1, num2, res;
String resS;
num1 = Double.parseDouble(jtfNum1.getText().trim());

num2 = Double.parseDouble(jtfNum2.getText().trim());
// +
if (ev.getSource() == jbtAdd) {
res = num1 + num2;
resS = Double.toString(res);
jtfRes.setText(resS);
}
//-
else if (ev.getSource() == jbtSub) {
res = num1 - num2;
resS = Double.toString(res);
jtfRes.setText(resS);
}
// *
else if (ev.getSource() == jbtMult) {
res = num1 * num2;
resS = Double.toString(res);
jtfRes.setText(resS);
}
// /
else if (ev.getSource() == jbtDiv) {
res = num1 / num2;
resS = Double.toString(res);
jtfRes.setText(resS);
}
else if (ev.getSource() == jbtC) {
jtfNum1.setText(null);
jtfNum2.setText(null);
jtfRes.setText(null);
}
}
}


