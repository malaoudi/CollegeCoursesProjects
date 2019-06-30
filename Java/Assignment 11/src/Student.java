
public class Student {
	private int id;
	private String name;
	//array. data_type [] variable
	private double[] exam;
	
	//constructor. created by the source. click on the left mouse
	public Student(int id, String name, double[] exam) {
		super();
		this.id = id;
		this.name = name;
		this.exam = exam.clone();	//clones the vlaue. creates a new array, sends a copy
	
	}
	

	public String findGrade () {
		double sum=0;
		for (int i= 0; i<exam.length; i++) {
			sum = sum + exam[i];
		}
		double avg=sum/exam.length;
		String grade;
		if (avg >= 90.0) {
			grade = "A";
		}
		else if (avg >= 80.0) {
				grade = "B";
			}
		else if (avg >= 70.0){
				grade = "C";
			}
		else if (avg >= 60.0){
			grade = "D";
		}	
		else {
			grade = "F";
		}
		
		return grade;	
	}
	
	//need to create get methods. go to any field constructor. use the source. choose geenerate getter and setters
	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public double[] getExam() {
		return exam.clone();
	}

	
	
	
}
