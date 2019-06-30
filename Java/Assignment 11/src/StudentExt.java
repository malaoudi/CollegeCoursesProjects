
public class StudentExt extends Student {
	private String gradeType;
	private String grade_final;
	
	public StudentExt(int id, String name, double [] exam, String gradeType){
		
		super(id, name, exam);
		this.gradeType = gradeType;
		
	}
		
	
//@override	
	
	public String findGradeType() {
		String grade = super.findGrade();
		if(gradeType.equalsIgnoreCase("Credit"))
			{
			if (grade.equals("A") ||
				(grade.equals("B")) || 
				(grade.equals("C")) )
			
			grade = "CR";
					
		else {
			grade = "NCR";
				
				}
		}
		
		return grade;
	
	}
	
	
	
	


}



