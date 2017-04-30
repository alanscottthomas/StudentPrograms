/*

Name: Mesa Spottedcorn, Kevin Magee, Alan Thomas

Class: CSI415

Assignment: Lab4 - train simulator portion

Purpose: Simulate 3 trains operating on a track consisting of numerous stops. Updates occur every 30 seconds.

Notes: This program accepts an argument from the command line to determine the train name. When launching the program
simply add A or B or C to launch their loop. I was more comfortable with this approach compared to threading.

*/

package lab4;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.TimeUnit;



public class Lab4 {
    
    public static void main(String[] args) throws InterruptedException 
    {
       for (String s: args)
       {
           System.out.println("\nLoading passengers on train "+args[0]+"....all aboard for the ride of your life.\n");
           start(args[0]);                                                    //calling start with variables passed in from the console. Decided to take this route instead of threading
        
       }
      
    }
    
    public static void next(String train,int next_stop)
    {
      try
    {
    
        String next_stop_string = Integer.toString(next_stop);    
// create our mysql database connection
      String myDriver = "org.gjt.mm.mysql.Driver";
      String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";
      Class.forName(myDriver);
      Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
      
      // our SQL SELECT query. 
      // if you only need a few columns, specify them by name instead of using "*"
      String query = "SELECT * FROM stops_tbl WHERE stop_number=?";               //selecting the row that matches the next stop
      PreparedStatement preparedStmt2 = conn.prepareStatement(query);
      preparedStmt2.setInt (1, next_stop);
      preparedStmt2.executeQuery();

      // create the java statement
      Statement st = conn.createStatement();
      
      // execute the query, and get a java resultset
      ResultSet rs = preparedStmt2.executeQuery();
      
      // iterate through the java resultset
      int next_stop_next=0;
      while (rs.next())
      {
        int stop_number = rs.getInt("stop_number");
        //System.out.println("\n"+stop_number+"\n");
        next_stop_next = rs.getInt("next_stop");
        //System.out.println("\n"+next_stop_next+"\n");
        int traverse_time = rs.getInt("traverse_time");
        
        int counter=0;
        while (traverse_time > 0)
        {
            
            TimeUnit.SECONDS.sleep(1);
            traverse_time=traverse_time-1;  //change the 30 to 1 after testing
            
            counter=counter+1;             //increment counter every second
            
            //if statement to place into the history table
            if (traverse_time==0)
            {
                String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());                      	
                String insert_query = "insert into history_tbl (train_name, arrival_time,current_stop,next_stop)"
                                    + " values (?, ?, ?,?)";

                // create the mysql insert preparedstatement
                PreparedStatement preparedStmt = conn.prepareStatement(insert_query);
                preparedStmt.setString (1, train);
                preparedStmt.setString (2, timeStamp);
                preparedStmt.setInt   (3, stop_number);
                preparedStmt.setInt   (4, next_stop_next);
      

                // execute the preparedstatement
                preparedStmt.execute();
                
            }
            
            //if statement to perform 30 second update
            if (counter==30)
            {
                    counter=0;                                                                //reset counter to 0 so we can perform another 30 sec update
                                          	
                    String update_query = "update current_tbl set train_name = ?,tt_next_stop=?,next_stop=? where train_name=?";  //string to update current location table

                // create the mysql insert preparedstatement
                    PreparedStatement preparedStmt = conn.prepareStatement(update_query);      
                    preparedStmt.setString (1, train);
                    preparedStmt.setInt (2, traverse_time);
                    preparedStmt.setInt   (3, next_stop_next);
                    preparedStmt.setString (4, train);
      

                // execute the preparedstatement
                    preparedStmt.execute();
                     
            }
        }
        
      }
      conn.close();                                             //closing connections
      st.close();
      
      next (train,next_stop_next);                             //calling next method with next stop
    }
    catch (Exception e)
    {
      System.err.println("Got an exception! ");
      System.err.println(e.getMessage());
    } 
    }
    //-------------------------------------------------------------------------//
    
    //START METHOD//
    public static void start(String train) 
    {
       
        try
    {
      // create our mysql database connection
      String myDriver = "org.gjt.mm.mysql.Driver";
      String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";
      Class.forName(myDriver);
      Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
      
  
      String query = "SELECT * FROM stops_tbl";

      // create the java statement
      Statement st = conn.createStatement();
      
      // execute the query, and get a java resultset
      ResultSet rs = st.executeQuery(query);
      
        int next_stop=0;  
      
        // iterate through the java resultset
      while (rs.next())
      {
        int stop_number = rs.getInt("stop_number");
        next_stop = rs.getInt("next_stop");
        int traverse_time = rs.getInt("traverse_time");
        
        int counter=0;
        //while loop to determine if it is time to move to the next stop
        while (traverse_time > 0)
        {
            
            TimeUnit.SECONDS.sleep(1);
            traverse_time=traverse_time-1;  //change the 30 to 1 after testing
            
            counter=counter+1;             //counter to mark when it is time for the 30 second updates
            
            //if statement to place into the history table
            if (traverse_time==0)
            {
                String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());                            //timestamp                  	
                String insert_query = "insert into history_tbl (train_name, arrival_time,current_stop,next_stop)"  //inserting train arrival time into the history table
                                    + " values (?, ?, ?,?)";

                // create the mysql insert preparedstatement
                PreparedStatement preparedStmt = conn.prepareStatement(insert_query);
                preparedStmt.setString (1, train);
                preparedStmt.setString (2, timeStamp);
                preparedStmt.setInt   (3, stop_number);
                preparedStmt.setInt   (4, next_stop);
      

                // execute the preparedstatement
                preparedStmt.execute();
                 next (train,next_stop);     //calling next with the next stop
                
            }
            
            //if statement to perform 30 second update
            if (counter==30)
            {
                    counter=0;

                   //String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());                      	
                    String update_query = "update current_tbl set train_name = ?,tt_next_stop=?,next_stop=? where train_name=?";

                // create the mysql insert preparedstatement
                    PreparedStatement preparedStmt = conn.prepareStatement(update_query);
                    preparedStmt.setString (1, train);
                    preparedStmt.setInt (2, traverse_time);
                    preparedStmt.setInt   (3, next_stop);
                    preparedStmt.setString (4, train);
      

                // execute the preparedstatement
                    preparedStmt.execute();
  
            }

        }
      
      }
      conn.close();              //close connections
      st.close();
      
    }
    catch (Exception e)
    {
      System.err.println("Got an exception! ");
      System.err.println(e.getMessage());
    }
  
    }
    
        
    }
  //---------------------------------------------------------------------//  

