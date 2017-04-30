/*
Name: Mesa Spottedcorn, Kevin Magee, Alan Thomas
Class: CSI415
Assignment: Lab1
Purpose: Accept input from a user and place it into MySQL using JDBC.
Notes: A few issues were incountered, such as, 0's being truncated in SQL. However,
this was remedied by adding UNSIGNED ZEROFILL to the SSN and phone fields. Additionally,
there were some confusing as to how to handle input validating, but this was eventually
figured out with a fair bit of Google-fu. We also implemented error logging, which we
tackled in our first Java assignment. Lastly, you are also able to display the worker_tbl
and delete entried from the table using the ID.
 */
package javaapplication1;
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

public class JavaApplication1 {
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
        System.out.print("(A) to Input a new user\n(B) to print current users in DB\n(C) to search for a user by last name\n(D) to delete an entry\n(Q) to quit");  //printing menu
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
                get_info();                                                             //call get_info method 
                break;
            case 'b':
            case 'B':
                print_users();                                                          //call print_users method
                break;
            case 'c':
            case 'C':
                search_last();                                                          //call delete_user method
                break;
            case 'd':
            case 'D':
                delete_user();                                                          //call delete_user method
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


//ADD USER METHOD//    
    public static void get_info() throws ClassNotFoundException, SQLException 
    {
        Scanner user_input = new Scanner(System.in);                                  //initiating scanner to accept user's input
        System.out.print("\n\n");
        //GETTING FIRST NAME//
        System.out.print("Enter the first name: ");                                   //input check of first name input
        Pattern valid_first=Pattern.compile("[aA-zZ]*");
        while(!user_input.hasNext(valid_first))
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the first name: ");
            user_input.next();   
        }
        String first_name = user_input.next();
        //--------------//

        //GETTING LAST NAME//
        System.out.print("Enter the last name: ");                                    //input check of last name
        Pattern valid_last = Pattern.compile("[aA-zZ]*");
        while(!user_input.hasNext(valid_last))
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the last name: ");
            user_input.next();  
        }
        String last_name = user_input.next();
        //--------------//

        //GETTING SSN //
        System.out.print("Enter the SSN ie(123456789): ");

        Pattern valid_ssn = Pattern.compile("[0-9]{9}");                            //used pattern to assist with input validation.
        while (!user_input.hasNextLong() || !user_input.hasNext(valid_ssn)) {       //while statement to detect if the input is valid
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the SSN ie(123456789): ");
            user_input.next();
        }
        Long ssn = user_input.nextLong();                                          //assigning user's input to the ssn variable
        //--------------// 

        //GETTING phone number //
        System.out.print("Enter the phone number ie(6181234567): ");
        Pattern valid_phone = Pattern.compile("[0-9]{10}");                        //used pattern to assist with input validation.
        while (!user_input.hasNextLong() || !user_input.hasNext(valid_phone))      //while statement to detect if the input is valid
        {

            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the phone number ie(6181234567): ");
            user_input.next();
        }

        Long phone_number = user_input.nextLong();                                //assigning user's input to the phone_number variable
        //--------------// 
//TRY STATEMENT TO INSERT DATA INTO THE DB//
        try 
            {
                String sql = "INSERT INTO worker_tbl (first_name, last_name, ssn, phone_number)" + "VALUES (?, ?, ?, ?)";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://localhost:3306/team2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, first_name);
                preparedStatement.setString(2, last_name);
                preparedStatement.setLong(3, ssn);
                preparedStatement.setLong(4, phone_number);
                Statement st = conn.createStatement();
                preparedStatement.executeUpdate();                                                                         //pushing the INSERT command to the DB    
                conn.close();                                                                                              //closing the connection                
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
                                    Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: INSERTING DATA INTO worker_tbl(get_info method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                                } 
                            else 
                                {
                                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                                    myfile.print("Error generated at: INSERTING DATA INTO worker_tbl(get_info method)  <" + timeStamp + ">");     //printing what method had an error
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

//DELETE METHOD//
    public static void delete_user() throws ClassNotFoundException, SQLException 
    {
        Scanner user_input = new Scanner(System.in);                           //initiating scanner to accept user's input
        System.out.print("\n\n");
        //GETTING ID//
        System.out.print("Enter the ID of the entry to delete: ");
        while (!user_input.hasNextLong())                                      //input validation
            {
                System.out.print("-Invalid Input-\n");
                System.out.print("Enter the ID of the entry to delete: ");
                user_input.next();
            }
//--------------//
        Long worker_id = user_input.nextLong();                                //assigning user's input to worker_id
        //TRY STATEMENT FOR DELETE//
        try 
         {
            String sql = "DELETE FROM worker_tbl WHERE worker_id= ?";          //creating the string we'll use to execute the DELETE
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://localhost:3306/team2?autoReconnect=true&useSSL=false";    //DB connection info
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");           //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);       
            preparedStatement.setLong(1, worker_id);
            Statement st = conn.createStatement();
            preparedStatement.executeUpdate();                                  //pushing the statement to the DB
            conn.close();                                                       //closing DB connection
         } 
        //CATCH STATEMENT IF WE COULD NOT DELETE//
        catch (Exception e) 
            {
                System.err.println("There was an error!\n\n");
                //TRY STATEMENT FOR CREATING ERROR LOG//
                try 
                    {
                        File f = new File("error_log.txt");
                        //IF STATEMENT FOR FILE EXISTENCE//
                        if (f.exists()) 
                            {
                                String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());        //creating a string with the current date and time
                                Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: DELETING DATA FROM worker_tbl(delete_user method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                            } 
                        //IF THE FILE EXIST DO THIS//
                        else 
                            {
                                PrintWriter myfile = new PrintWriter("error_log.txt");                                          //creating a txt file in the directory that the program resides in
                                String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());            //creating a string with the current date and time
                                myfile.print("Error generated at: DELETING DATA FROM worker_tbl(delete_user method)  <" + timeStamp + ">");  //printing date/time and method location of fault
                                myfile.close();
                            }//closing the file we have open
                    } 
                //CATCH STATEMENT FOR LOG WRITE FAILURE//
                catch (IOException b) 
                    {                                                                
                        System.out.println("-Unable to generate log file-");    //statement to print an error in the event we couldn't write/create the file    
                    }
            }
        main(null);
    }
//--------------------------------//

    //PRINT USERS METHOD//   
    public static void print_users() throws ClassNotFoundException, SQLException 
    {
        System.out.print("\n\n");
        System.out.print("| id | first | last | SSN | phone |\n");
        System.out.print("______________________________________\n");
        //TRY STATEMENT FOR PULLING INFO FROM DB//
        try 
            {
                Class.forName("com.mysql.jdbc.Driver").newInstance();
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/team2?autoReconnect=true&useSSL=false", "root", "password123");  //DB connection info
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("select * from worker_tbl");           //selecting all entries from the worker_tbl
                    while (rs.next()) 
                        {
                            System.out.println("| " + rs.getLong(1) + "| " + rs.getString(2) + " | " + rs.getString(3) + " | " + rs.getString(4) + " | " + rs.getString(5) + " |");   //id first last ssn phone
                        }
                con.close();                                                            //closing connection
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
                            Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: RETRIEVING DATA FROM worker_tbl(print_users method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                        } 
                    else 
                        {
                            PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                            String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                            myfile.print("Error generated at: RETRIEVING DATA FROM worker_tbl(print_users method)  <" + timeStamp + ">"); //printing method location & timestamp to the file
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

//SEARCH BY LAST NAME METHOD//
public static void search_last() throws ClassNotFoundException, SQLException 
    {
        //GETTING LAST NAME//
        Scanner user_input = new Scanner(System.in); 
        System.out.print("Enter the last name: ");                                    //input check of last name
        Pattern valid_last = Pattern.compile("[aA-zZ]*");                             //kleen
        while(!user_input.hasNext(valid_last))
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the last name: ");
            user_input.next();  
        }
        String last_name = user_input.next();
        //--------------//
        
     
  
//TRY STATEMENT TO INSERT DATA INTO THE DB//
        try 
            {
                System.out.print("\n\n");
                System.out.print("| id | first | last | SSN | phone |\n");
                System.out.print("______________________________________\n");
                String sql = "SELECT * FROM worker_tbl WHERE last_name=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://localhost:3306/team2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, last_name);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                
               
                Statement st = conn.createStatement();
                                                                                         //pushing the INSERT command to the DB    
                
                 while (rs.next()) 
                        {
                            System.out.println("| " + rs.getLong(1) + "| " + rs.getString(2) + " | " + rs.getString(3) + " | " + rs.getString(4) + " | " + rs.getString(5) + " |");   //id first last ssn phone
                        }
                
                conn.close();                                                                                              //closing the connection                
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
           + "|__|__|\\____||___|___||_____|    |_____||_____|     \\____| \\___/ |__|\n\u00a9 2017 Mesa Spottedcorn, Kevin Magee, and Alan Thomas"); 
}
//-------------//

//----END PROGRAM----//
}

