import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class JPanelExt extends JPanel {
	private String pictureType = "happy";
	public JPanelExt() {		//constructore
	}
	
	public void paintComponent(Graphics g) {	//paint method
		
		super.paintComponent(g);    //call the parent method
		System.out.println("paintComponent");
		//g.setColor(Color.yellow);	//include the code that does the drawing
		
		g.drawString("hi", 50, 50);
		if(pictureType.equals("Happy")){
		      g.drawOval(0,0,100,100);
		      g.fillOval(25,25,10,10);
		      g.fillOval(65,25,10,10);
		      g.drawArc(25,25, 50,50,0,-180);
		}
		else if (pictureType.equalsIgnoreCase("sad")){
			   g.setColor(Color.GREEN);
	           g.fillOval(0,0,300,300);
	           g.setColor(Color.black );
	           g.fillOval(80,75,30,30);
	           g.fillOval(190,75,30,30);
	           g.setColor(Color.black);
	           g.drawArc(75,150,150,150,0,180);
	           
		}
		else {
			ImageIcon imageIcon = new ImageIcon ("myfile.gif");
			  Image image  = imageIcon.getImage();
			g.drawImage (image,0,0,this.getWidth(), this.getHeight(), this); //where g is a Graphics object.
		}
				
	}
	
	
	public void setPictureType(String pType) {
		String picType;
		this.pictureType = pType;
		System.out.println("SetPictureType");
		repaint();
	}
	
}

//put the pictures in main.