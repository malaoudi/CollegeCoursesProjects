import javax.swing.JOptionPane;

public class TestSiblingExt {
	public static void main (String args[]){
		String in, out;
		String name = null;
		int age=0, weight = 0, height=0;
		
		//SiblingExt object = new SiblingExt(name, age, weight, height);	//object

		
		name =JOptionPane.showInputDialog("Enter name");
		in = JOptionPane.showInputDialog("Enter age");
		age = Integer.parseInt(in);
		
		in = JOptionPane.showInputDialog("Enter weight");
		weight = Integer.parseInt(in);
		
		in = JOptionPane.showInputDialog("Enter height");
		height = Integer.parseInt(in);
		//create the first sibling object 
		//class object = new Extended_Class constructor
		SiblingExt sibe1 = new SiblingExt(name,age,weight,height);
		
		//create another sib
		
		name =JOptionPane.showInputDialog("Enter name");
		in = JOptionPane.showInputDialog("Enter age");
		age = Integer.parseInt(in);
		
		in = JOptionPane.showInputDialog("Enter weight");
		weight = Integer.parseInt(in);
		
		in = JOptionPane.showInputDialog("Enter height");
		height = Integer.parseInt(in);
		//create the first sibling object 
		//class object = new Extended_Class constructor
		SiblingExt sibe2 = new SiblingExt(name,age,weight,height);
		
		//creather 3ed sib
		
		name =JOptionPane.showInputDialog("Enter name");
		in = JOptionPane.showInputDialog("Enter age");
		age = Integer.parseInt(in);
		
		in = JOptionPane.showInputDialog("Enter weight");
		weight = Integer.parseInt(in);
		
		in = JOptionPane.showInputDialog("Enter height");
		height = Integer.parseInt(in);
		//create the first sibling object 
		//class object = new Extended_Class constructor
		SiblingExt sibe3 = new SiblingExt(name,age,weight,height);
		
		//find the lgihtest. can use if loop. compairson 
				SiblingExt lightest = null;
				if (sibe1.getWeight() <= sibe2.getWeight() &&  
						sibe1.getWeight() <= sibe3.getWeight() )
				{
				lightest = sibe1;
				}
				
				else if (sibe2.getWeight() <= sibe1.getWeight() &&
						sibe2.getWeight() <= sibe3.getWeight() )
				{
				lightest = sibe2;
				}
				else  
				{
				lightest = sibe3;
				}
				
				
				//create a reference variable for the youngest
				SiblingExt youngest = null;
				
				//youngest
				if (sibe1.getAge() <= sibe2.getAge() &&  
						sibe1.getAge() <= sibe3.getAge() )
				{
				youngest = sibe1;
				}
				else if (sibe2.getAge() <= sibe1.getAge() &&
						 sibe2.getAge() <= sibe3.getAge())
				{
				youngest = sibe2;
				}
				else  
				{
				youngest = sibe3;
				}
				
				
				//tallest
				SiblingExt tallest;
				if (sibe1.getHeight() <= sibe2.getHeight() &&  
						sibe1.getHeight() <= sibe3.getHeight() )
				{
				tallest = sibe1;
				}
				else if (sibe2.getHeight() <= sibe1.getHeight() &&
						 sibe2.getHeight() <= sibe3.getHeight())
				{
				tallest = sibe2;
				}
				else  
				{
				tallest = sibe3;
				}
				
				
				

				
				//output
				out = "The lightest sibling:  " + 
						  lightest.getName() + " " +
						  lightest.getAge() + " " +
						  lightest.getWeight() + " \n"  +
						  lightest.getHeight() + " \n" ;
				
				out = out + "The youngest sibling:  " + 
						  youngest.getName() + " " +
						  youngest.getAge() + " " +
						  youngest.getWeight() + " \n" +
						  youngest.getHeight() + " \n";
				
				out = out + "The tallest sibling:  " + 
						  tallest.getName() + " " +
						  tallest.getAge() + " " +
						  tallest.getWeight() + " \n" +
						  tallest.getHeight() + " \n";
				//display output
				JOptionPane.showMessageDialog(null, out);
				
			}

	

		
		
	}
	
	
	

