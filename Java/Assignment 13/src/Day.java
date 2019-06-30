
public class Day {
	
	private int day;
	
	protected int month;
	private int year;

	
	//public constructor to intialize the variable
	
	//Format for consturctors 
	//public class(data_type varibale, data_type variable) { 
	//super();
	//this.variable = variable;

//}

	public Day(int day, int month) {
		super();
		this.day = day;
		this.month = month;
		

	}
	


	
	public int getDay() {
		return day;
	}

	public int getMonth() {
		return month;
	}

	public int getYear() {
		
		return year;
	}
	
	public int findDayNum() {
		
		if (month == 2) {
            day += 31;
            }
       else if (month == 3) {
          day += 59;
          }
       else if (month == 4) {
          day += 90;
          }
       else if (month == 5) {
          day += 31 + 28 + 31 + 30;
          }
       else if (month == 6) {
          day += 31 + 28 + 31 + 30 + 31;
          }
       else if (month == 7) {
          day += 31 + 28 + 31 + 30 + 31 + 30;
          }
       else if (month == 8) {
          day += 31 + 28 + 31 + 30 + 31 + 30 + 31;
          }
       else if (month == 9) {
          day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
          }
       else if (month == 10) {
          day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
          }
       else if (month == 11) {
          day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
          }
       else if (month == 12) {
          day += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
          }
		
		
		return day;
	}
	
}
