/*
Name: Mesa Spottedcorn, Kevin Magee, Alan Thomas
Class: CSI415
Assignment: Lab2
Purpose: Accept a student's lastname from the user and calculate the GPA using the database.
Notes: This probably isn't the cleanest implementation, but it works. Instead of relying strictly on the DB to make our calculations,
we saved the information into variables inside of Java as we thought this would provide an easier means to compute GPAs as we are more
familiar with C++(esque) programming rather than SQL. 

 */
package lab2;
//LIBRARIES//
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.io.File;
import java.io.PrintWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.text.SimpleDateFormat;
import java.util.Date;
//----------------------//

public class Lab2 {
static boolean intro=true;                                                              //set to true for awesome ASCII art

//MAIN METHOD//
    public static void main(String[] args) throws ClassNotFoundException, SQLException 
    {
        //IF STATEMENT FOR STYLE POINTS//
        if(intro==true)
            {
                intro=false;
                intro();
            }
        //END ANY STYLE WE HAVE//
        
        Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
        System.out.print("\n\n");
        System.out.print("==========MENU==========\n");
        System.out.print("(A) to print current users in DB\n(B) to search for a user by last name\n(Q) to quit");  //printing menu
        System.out.print("\n=========================\n");
        System.out.print("Input: ");
        
        Pattern valid_ans=Pattern.compile("[aA-zZ]");
        while(!user_input.hasNext(valid_ans))                                            //input validation for menu selection
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter menu option: ");
            user_input.next();   
        }     
        char ans = user_input.next(".").charAt(0);                                      //placing the user's input into a char
//SWITCH STATEMNT FOR USER SELECTION//
        switch (ans) {
          
            case 'a':
            case 'A':
                print_users();                                                          //calling the method to print the contents of the DB
                break;
            case 'b':
            case 'B':
                search_last();                                                          //calling the method to calculate the GPA of a particular student.
                break;          
            case 'q':
            case 'Q':
                break;
            default:
                System.out.println("\n-Invalid Selection-");
                main(null);                                                             //I don't like calling main recursively, but I couldn't get the switch to work otherwise.
 //END SWITCH//               
        }
    }
//---------------------------//


 


    //PRINT USERS METHOD//   
    public static void print_users() throws ClassNotFoundException, SQLException 
    {
        System.out.print("\n\n");
        System.out.print("| ID | Last | Class | Major |\n");
        System.out.print("______________________________________\n");
        //TRY STATEMENT FOR PULLING INFO FROM DB//
        try 
            {
                Class.forName("com.mysql.jdbc.Driver").newInstance();
                Connection con = DriverManager.getConnection("jdbc:mysql://68.188.20.101:3306/team2_lab2?autoReconnect=true&useSSL=false", "root", "password123");  //DB connection info
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("select * from student_tbl");           //selecting all entries from the student_tbl
                    while (rs.next()) 
                        {
                            System.out.println("| " + rs.getLong(1) + " | " + rs.getString(2) + " | " + rs.getString(3) + " | " + rs.getString(4) + " | ");   //id,last,class,major
                        }
                con.close();                                                            //closing connection
                try 
                    {
                        File f = new File("error_log.txt");                                  //attempting to create the log file to document our access times
                            if (f.exists()) 
                                {
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm:ss.SSS").format(new Date());                            //creating a string with the current date and time
                                    Files.write(Paths.get("error_log.txt"), ("\r\nStudent DB was accessed at: "+"<" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                                } 
                            else 
                                {
                                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm:ss.SSS").format(new Date());                           //creating a string with the current date and time
                                    myfile.print("Student DB was accessed at: "+"<"+"  <" + timeStamp + ">");     //printing what method had an error
                                    myfile.close();
                                }
            } 
                //CATCH STATEMENT IF FILE CREATIONG FAILED//
                catch (IOException b) 
                    {                                                                          
                        System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
                    }
                
            } 
        //CATCH STATEMENT IF WE COULDN'T PULL DATA//
        catch (Exception e) 
            {
                System.out.println("-Error detected- Unable to print information-");
            }
       
        //TRY STATEMENT FOR CREATING ERROR FILE//
        try 
            {
                File f = new File("error_log.txt");
                    if (f.exists()) 
                        {
                            String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());        //creating a string with the current date and time
                            Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: RETRIEVING DATA FROM student_tbl(print_users method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                        } 
                    else 
                        {
                            PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                            String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                            myfile.print("Error generated at: RETRIEVING DATA FROM student__tbl(print_users method)  <" + timeStamp + ">"); //printing method location & timestamp to the file
                            myfile.close();
                        }
            } 
        //CATCH STATEMENT IF WE FAILED TO WRITE TO THE FILE..    
        catch (IOException b) 
                {                                                                          
                    System.out.println("-Unable to generate log file-");       
                }
        //-------------------------------------------//
        System.out.print("______________________________________\n");
        main(null);
    }
//------------------------//

//PRINT GPA OF STUDENT//
public static void search_last() throws ClassNotFoundException, SQLException 
    {
        //GETTING LAST NAME//
        Scanner user_input = new Scanner(System.in); 
        System.out.print("Enter the last name: ");                                    //input check of last name
        Pattern valid_last = Pattern.compile("[aA-zZ]*");                             //kleene
        while(!user_input.hasNext(valid_last))
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the last name: ");
            user_input.next();  
        }
        String name = user_input.next();
        //--------------//
        
     
  
//TRY STATEMENT TO QUERY DATA FROM THE DB//
        try 
            {
                System.out.print("\n\n");
                System.out.print("| GPA CALCULATION |\n");
                System.out.print("______________________________________\n");
                String sql = "SELECT student_number FROM student_tbl WHERE name=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/team2_lab2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                String student_id=null;
               
                Statement st = conn.createStatement();
                                                                                             
                
                 while (rs.next())                                                         //while look to get the student's ID. Don't need a while, but it's working, so I'm not going to break it.
                        {
                            
                            student_id=rs.getString(1);
                           System.out.print(name+"'s GPA is: ");
                           
                        }
                 
                 
                 conn.close(); 
                 
                String sql2 = "SELECT grade FROM grade_report_tbl WHERE student_number=?";  //creating a string we'll use to insert into the DB
                String myDriver2 = "org.gjt.mm.mysql.Driver";
                String myUrl2 = "jdbc:mysql://68.188.20.101:3306/team2_lab2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver2);
                Connection conn2 = DriverManager.getConnection(myUrl2, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement2 = conn2.prepareStatement(sql2);                                          //prepared statement to insert info into table
                preparedStatement2.setString(1, student_id);
                preparedStatement2.executeQuery();
                ResultSet rs2 = preparedStatement2.executeQuery();
                
                String student_id2=null;
               
                Statement st2 = conn2.createStatement();
                
                try 
                    {
                        File f = new File("error_log.txt");                                  //attempting to create the access log file
                            if (f.exists()) 
                                {
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm:ss.SSS").format(new Date());                            //creating a string with the current date and time
                                    Files.write(Paths.get("error_log.txt"), ("\r\nStudent DB was accessed at: "+"<" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                                } 
                            else 
                                {
                                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm:ss.SSS").format(new Date());                           //creating a string with the current date and time
                                    myfile.print("Student DB was accessed at: "+"<"+"  <" + timeStamp + ">");     //printing access time to log
                                    myfile.close();
                                }
            } 
                //CATCH STATEMENT IF FILE CREATIONG FAILED//
                catch (IOException b) 
                    {                                                                          
                        System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
                    }
                
                                                                                         //pushing the INSERT command to the DB    
                int count=0;
                float grade=0;
                
                 while (rs2.next()) 
                        {
                            count++;  //increment count to be used in calculating the GPA.
                            
                            student_id2=rs2.getString(1);

                            if(student_id2.equals("A"))
                            {
                                grade=grade+4;  
                            }
                            
                            if(student_id2.equals("B"))
                            {
                                grade=grade+3; 
                            }
                            
                            if(student_id2.equals("C"))
                            {
                                grade=grade+2;
                            }
                            
                            if(student_id2.equals("D"))
                            {
                                grade=grade+1;                               
                            }
                            
                            if(student_id2.equals("F"))
                            {
                                grade=grade+0;   
                            }
                        }
                 
                 System.out.print(grade/count);
                 System.out.print("\n______________________________________\n");
                 
                conn2.close();                                                                                              //closing the connection                
            } 
        //CATCH STATEMENT INCASE OF AN ERROR//
        catch (Exception e) 
            {
                System.err.println("There was an error!\n\n");
                //TRY STATEMENT TO CREATE ERROR LOG FILE//
                try 
                    {
                        File f = new File("error_log.txt");                                  //attempting to create the log file
                            if (f.exists()) 
                                {
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                            //creating a string with the current date and time
                                    Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: SEARCH FOR DATA FROM worker_tbl(search_last method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                                } 
                            else 
                                {
                                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                                    myfile.print("Error generated at: SEARCH FOR DATA FROM worker_tbl(search_last method)  <" + timeStamp + ">");     //printing what method had an error
                                    myfile.close();
                                }
            } 
                //CATCH STATEMENT IF FILE CREATIONG FAILED//
                catch (IOException b) 
                    {                                                                          
                        System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
                    }
        }
        main(null);
    }
//--------------------//


//MOST IMPORTANT METHOD//    
public static void intro()
{
   System.out.println("\n  ____    __  ___ ___    ___      ___    ____          __   ___    \n /    |  /  ]|   |   |  /  _]    |   \\  |    \\        /  ] /   \\    \n"
           + "|  o  | /  / | _   _ | /  [_     |    \\ |  o  )      /  / |     |  \n|     |/  /  |  \\_/  ||    _]    |  D  ||     |     /  /  |  O  |   \n"
           + "|  _  /   \\_ |   |   ||   [_     |     ||  O  |    /   \\_ |     | __\n|  |  \\     ||   |   ||     |    |     ||     |    \\     ||     ||  |\n"
           + "|__|__|\\____||___|___||_____|    |_____||_____|     \\____| \\___/ |__|\n Lab2:StudentDB\u00a9 2017 Mesa Spottedcorn, Kevin Magee, and Alan Thomas"); 
}
//-------------//

//----END PROGRAM----//
}
