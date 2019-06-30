package demoof;


import javax.swing.JOptionPane;

public class Rectangle implements Status {
	private double length;
	private double width;
	
	
	//constructors
	public Rectangle(double length, double width) {
		super();
		this.length = length;
		this.width = width;
	}


	public String getStatus() {
		String status = "Rectangle: \n" + length;
		status = status + "length = " + length + " width = " + width;
		
			
		return status;
	}


	public void displayStatus() {
		String status = getStatus();
		
		JOptionPane.showMessageDialog(null, status);
		
		
	}
	
	//put the rectangle in the polymorphic array
	
	//define an interface and the methods and implement 
	
}

