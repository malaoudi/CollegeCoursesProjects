import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class JFrameExt extends JFrame implements ActionListener {
	private JPanel jp = new JPanel();  //object
	private JPanelExt jpe = new JPanelExt();
	private JButton jbtHappy = new JButton ("happy");
	private JButton jbtSad = new JButton ("sad");
	private JButton jbtPicture = new JButton ("picture");

	
	private JPanel jpMain = new JPanel();
	public JFrameExt() {				//method
		this.setContentPane(jpMain);
		
		
		jpMain.setBackground(Color.green);
		
		BorderLayout bl = new BorderLayout();
		jpMain.setLayout(bl);
		
		jpMain.add(jpe, BorderLayout.CENTER);
		jpMain.add(jp, BorderLayout.SOUTH);
		jpMain.add(jpe);
		jpMain.add(jp);
		//jp.setBackground(Color.yellow);
		jpe.setBackground(Color.yellow);
		jp.setBackground(Color.cyan);
		//register the buttons
		jp.add(jbtSad);
		jp.add(jbtHappy);
		jp.add(jbtPicture);
		
		//jframe needs to be a listener to use actionlistenre
		jbtHappy.addActionListener(this);
		jbtSad.addActionListener(this);
		jbtPicture.addActionListener(this);

	}
	
	@Override
	//recgnoizing the buttons
	public void actionPerformed(ActionEvent ev) {
		if(ev.getSource() == jbtHappy) {
			jpe.setPictureType("Happy");
			
		}
		if(ev.getSource() == jbtSad) {
			jpe.setPictureType("Sad");
		}
		if(ev.getSource() == jbtPicture) {
			jpe.setPictureType("Picture");
		}
		
	}
	
}
