package demoof;

import javax.swing.JOptionPane;

public class Student implements Status{
	private int id;
	private String name;
	private double[] examsScores;
	
	//we need to create and object so we need a counstroctor. 

	public Student(int id, String name, double[] examsScores) {
		super();
		this.id = id;
		this.name = name;
		this.examsScores = examsScores;
	}

	@Override
	public String getStatus() {
		String status = "student:\n";
		status = status + "id " +id + "\n name " +name + "\n exam scores " + examsScores;
		
		status = status + "scores: ";
		for (int i=0; i< examsScores.length; i++){
				status = status + examsScores[i] + " "; 
				
		}
		
		return status;
	}

	@Override
	public void displayStatus() {
		String status = getStatus();
		
		JOptionPane.showMessageDialog(null, status);
		
		
		
	}
	
}
