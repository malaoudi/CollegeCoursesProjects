package demoof;

import javax.swing.JOptionPane;

public class TestStatus {

	public static void main(String[] args) {
		//perfrom polymorphism in main. 
		
		String in, out, name;
		double length, width;
		int  age, weight, id, examCount;
		//double[] examScores;
		
		//create array of statuses. create status object
		//can not do new to create object but can use status references
		//an array of status
		Status [] stat = new Status [6];		//polymorphism
		//an array of different objects
		
		int iStat=0;
		for (int i =0; i < 3 ; i++){
		//input, get the l,w
			in = JOptionPane.showInputDialog("Enter length");
			length = Double.parseDouble(in);
			in = JOptionPane.showInputDialog("Enter width");
			width = Double.parseDouble(in);
			//create the object
			new Rectangle (length, width);
			//where to store it
			stat[iStat] = new Rectangle (length,width);
			iStat++;
		}
		
		for (int i =0; i < 2 ; i++){
			//input, get the l,w
				name = JOptionPane.showInputDialog("Enter age");
				in = JOptionPane.showInputDialog("Enter age");
				age = Integer.parseInt(in);
				in = JOptionPane.showInputDialog("Enter weight");
				weight = Integer.parseInt(in);
				//create the object
				new Sibling (name, age, weight);
				//where to store it
				stat[iStat] = new Sibling (name, age, weight );
				iStat++;
			}
		
		
		for (int i =0; i < 1 ; i++){
			
			
			in = JOptionPane.showInputDialog("Enter id");
			id = Integer.parseInt(in);
			name = JOptionPane.showInputDialog("Enter name");
			in = JOptionPane.showInputDialog("Enter exams count");
			examCount = Integer.parseInt(in);
			//object
			double[] examScores = new double [examCount];
			
				for (int j =0; j < examCount ; j++){
					in = JOptionPane.showInputDialog("Enter score");
					examScores[j]=Double.parseDouble(in);
				}

			stat[iStat] = new Student (id,name,examScores);
			iStat++;
			
			}
		//polymorphic loop. helds the statuses. 
		String status = "";
		for (int i=0; i<stat.length; i++){
			status += stat[i].getStatus();
		
			
			
			
			
				}
		
		
		JOptionPane.showMessageDialog(null,status);
		
		
	}

}
