
public class Main {

	public static void main(String[] args) {
		double north = 20;
		double south = 25 ;
		double east = 15;
		double west = 35;
		double midWest = 10;
		
		//constructor
		JFrameExt f = new JFrameExt(north,south,east,west,midWest);
		f.setSize(600,600);
		f.setVisible(true);
			
	}

}

import java.awt.Color;
import java.awt.Graphics;
import java.awt.HeadlessException;

import javax.swing.JFrame;

public class JFrameExt extends JFrame{
    private double n;
    private double s;
    private double e;
    private double w;
    private double mw;
    
    
    public JFrameExt(double n, double s, double e, double w, double mw) throws HeadlessException {
        super();
        this.n = n;
        this.s = s;
        this.e = e;
        this.w = w;
        this.mw = mw;
    }
    
    //public JFrameExt(double n, double s, double e, double w, double mw) {
    
    
    
    //what does override do
    @Override
    public void paint (Graphics g){        //paint method
        super.paint(g);        //clearn up
        double total;
        total = n+s+e+w+mw;
        //    g.drawString("hi", 100, 50); //down movement, right movement
        //g.drawRect(50, 50, 400, 200);  //g.drawRect(x,y,wid,hight) , draw rectangle shape
        //g.drawOval(50,50,400,200);        //this is the ellipse inside the rectnale, then
        
        g.setColor(Color.red);
        
        int startAngle = 0 ;
        int arcWidth = 0;
        
        
        g.setColor(Color.red);
        startAngle = startAngle + arcWidth;
        arcWidth = (int) (n/total * 360);     //casting (int)
        g.fillArc(50,50,400,400,startAngle,arcWidth);         //default methods provided. drawVariable(), fill()
        
        g.setColor(Color.green);
        startAngle = startAngle+ arcWidth ;
        arcWidth = (int) (s/ total * 360);
        g.fillArc(50, 50, 400, 400, startAngle, arcWidth);
        
        g.setColor(Color.blue);
        startAngle = startAngle + arcWidth ;
        arcWidth = (int) (e/ total * 360);
        g.fillArc(50, 50, 400, 400, startAngle, arcWidth);
        
        g.setColor(Color.magenta);
        startAngle = startAngle+ arcWidth ;
        arcWidth = (int) (w/ total * 360);
        g.fillArc(50, 50, 400, 400, startAngle, arcWidth);
        
        g.setColor(Color.yellow);
        startAngle = startAngle + arcWidth ;
        arcWidth = (int) (mw/ total * 360);
        g.fillArc(50, 50, 400, 400, startAngle, arcWidth);
        
        //legends marking
        g.setColor(Color.red);
        g.drawString("hi", 100, 50);
        
        g.setColor(Color.red);
        //g.fillRect(x, y, width, height);
        g.fillRect(50,490, 30, 15);
        //g.drawString(str, x, y);
        g.drawString("north - 20.0", 90, 500);
        
        
        g.setColor(Color.green);
        g.fillRect(50,510, 30, 15);
        g.drawString("south - 25.0", 90, 520);
        
        g.setColor(Color.blue);
        g.fillRect(50,530, 30, 15);
        g.drawString("east - 15.0", 90, 540);
        
        g.setColor(Color.magenta);
        g.fillRect(50,550, 30, 15);
        g.drawString("west - 10.0", 90, 560);
        
        
        g.setColor(Color.yellow);
        g.fillRect(50,570, 30, 15);
        g.drawString("midwest - 35.0", 90, 580);
        
        
        
    }
    
}
