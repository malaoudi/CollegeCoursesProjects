package demoof;

import javax.swing.JOptionPane;

public class Sibling implements Status{
	private String name;
	private int age;
	private int weight;
	public Sibling(String name, int age, int weight) {
		super();
		this.name = name;
		this.age = age;
		this.weight = weight;
	
	}
	
	@Override
	public String getStatus() {
		String status = "sibling:\n";
		status = status + "name " +name + "\nage " +age + "\nweight " + weight;

		
		return status;
	}
	@Override
	public void displayStatus() {
		
		String status = getStatus();
		JOptionPane.showMessageDialog(null, status);
		
		
	}
	
	//create constructors. Can be created by the eclipse source
	//implement status. Provide the methods in the body. 
	
	
}
