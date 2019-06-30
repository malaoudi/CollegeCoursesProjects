
import javax.swing.JOptionPane;

public class TestLeapDay {

	public static void main (String argus[]){
		String in;
		int day, month, year;
	/*	
		in = JOptionPane.showInputDialog("Enter day");
		day = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter month");
		month = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter year");
		year = Integer.parseInt(in);
		
		Day b;	//object
		b = new Day(day,month);
		
	
	in = "The day number for " + month  +"/" + day + " is "+ year 
	+ b.findDayNum();
		
		*/
		
		in = JOptionPane.showInputDialog("Enter day");
		day = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter month");
		month = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter year");
		year = Integer.parseInt(in);
		
		
		LeapDay v;
		v = new LeapDay(day,month,year);
		in = "Day number is " + day + "/" + month + "/" + year + " is "
				+v.findDayNum();
		
		JOptionPane.showMessageDialog(null,in);
	
		
	}
}
