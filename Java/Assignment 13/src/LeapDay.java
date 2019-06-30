
public class LeapDay extends Day {
	private int year;
	//private int day;
	//private int month;
	
	LeapDay a;

	
	public LeapDay(int day, int month, int year) { 
		super(day,month);
		
		this.year = year;

	}
	
	
	public int getYear() {
		
	        //Not a leap year
	

		
		
		return year;
	}
	
	public int findDayNum() {
		int countDay;
		
		if (((year % 400) == 0) ||  (((year %   4) == 0) && ((year%100) != 0)))     
	{
			
		
				countDay = super.findDayNum();
				if (month >=2)
					countDay += 1;
				return countDay;
				
				
		}
		else
			
		{
			countDay = super.findDayNum();
			return countDay;
			
		}
	}
	
	
}
