

public class SiblingExt extends Sibling{	//extends the class sibling
	//blueprint of the previous class. 
		  private int height;
		  
		  public SiblingExt (String n, int a, int w, int h )
		           {
		                    super (n,a,w );	//firs tinstrcution in the method, siblext will class sibl construntor.
		                    //calls the object constructor. *chain of construcotrs 
		                    this.height = h;
		           }
		  		  
		  
		  //call the method
		           public int getHeight ( )
		           {
		        	   
		                    return height;
		           }
		
	
		           
		           
		           
		           
		           
		           
		           
		           
		           
		           
	
	
}
