/*

Name: Mesa Spottedcorn, Kevin Magee, Alan Thomas

Class: CSI415

Assignment: Lab4 - user portion

Purpose: Allows a user to check current location, history, add a stop, and remove a stop.

Notes: None
*/
package lab4_user;


import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.regex.Pattern;


/**
 *
 * @author Alan
 */
public class Lab4_user {

    //static int counter = 11;                                                           

    //MAIN METHOD//
    public static void main(String[] args) {
        Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
        System.out.print("\n\n");
        System.out.print("==========MENU==========\n");
        System.out.print("(A) to get current train location on the track\n(B) to view the history of a train \n(C) to add a stop\n(D) to delete a stop\n(E) to print stops\n(Q) to quit");  //printing menu
        System.out.print("\n=========================\n");
        System.out.print("Input: ");

        Pattern valid_ans = Pattern.compile("[aA-zZ]");                                 //input checking
        while (!user_input.hasNext(valid_ans))                                          //input validation for menu selection
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter menu option: ");
            user_input.next();
        }
        char ans = user_input.next(".").charAt(0);                                      //placing the user's input into a char
        //SWITCH STATEMNT FOR USER SELECTION//
        switch (ans) {

            //get current location
            case 'a':
            case 'A':
                get_current();
                break;

            //get history
            case 'b':
            case 'B':
                get_history();
                break;

            //add stop
            case 'c':
            case 'C':
                add_stop();
                break;

            //delete stop
            case 'd':
            case 'D':
                delete_stop();
                break;

            //print stop
            case 'e':
            case 'E':
                print_stops();
                break;

            //quit    
            case 'q':
            case 'Q':
                break;
            //default statement
            default:
                System.out.println("\n-Invalid Selection-");
                main(null);                                                             //I don't like calling main recursively, but I couldn't get the switch to work otherwise.
            //END SWITCH//               
        }
    }

    //METHOD TO PRINT STOPS//
    public static void print_stops() {

        //TRY STATEMENT TO PRINT STOP INFORMATION//
        try {
            System.out.print("\n\n");
            System.out.print("| Stop number |    Next stop      | Time till next stop |\n");
            System.out.print("__________________________________________________\n");
            String sql = "SELECT * FROM stops_tbl order by stop_number ASC";                                            //creating a string we'll use to insert into the DB
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";                  //connection info for the DB
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
            preparedStatement.executeQuery();                                                                          //executing the prepared statement                                                                        
            ResultSet rs = preparedStatement.executeQuery();                                                           //saving the results to a resultset

            //Statement st = conn.createStatement();
            //pushing the INSERT command to the DB    
            
            //while statement to print the results//
            while (rs.next()) {
                System.out.println("|      " + rs.getString(1) + "      |         " + rs.getLong(2) + "        |       " + rs.getLong(3) + "           |");
            }

            System.out.print("__________________________________________________\n");
            conn.close();                                                                                              //closing the connection                
        } 

        //CATCH STATEMENT INCASE OF AN ERROR//
        catch (Exception e) {
            System.err.println("There was an error!\n\n");
            //TRY STATEMENT TO CREATE ERROR LOG FILE//
            try {
                File f = new File("error_log.txt");                                  //attempting to create the log file
                if (f.exists()) {
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                            //creating a string with the current date and time
                    Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: SEARCH FOR DATA FROM worker_tbl(search_last method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                } else {
                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                    myfile.print("Error generated at: SEARCH FOR DATA FROM worker_tbl(search_last method)  <" + timeStamp + ">");     //printing what method had an error
                    myfile.close();
                }
            } //CATCH STATEMENT IF FILE CREATIONG FAILED//
            catch (IOException b) {
                System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
            }
        }
        main(null);

    }
//-------------------//

//METHOD TO GET CURRENT LOCATION OF A TRAIN//
    public static void get_current() {

       
        Scanner user_input = new Scanner(System.in);
        System.out.print("Enter the name of the train: ");                            //input check of last name
        Pattern valid_name = Pattern.compile("[aA-zZ]*");                             //A-Z with kleen
        //while loop for input validation
        while (!user_input.hasNext(valid_name)) {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the name of the train: ");
            user_input.next();
        }
        String name = user_input.next();                                              //saving input into a string
        //--------------//

        //TRY STATEMENT TO INSERT DATA INTO THE DB//
        try {
            System.out.print("\n\n");
            System.out.print("| Train name | Time till next stop | Destination |\n");
            System.out.print("__________________________________________________\n");
            String sql = "SELECT * FROM current_tbl WHERE train_name=?";  //creating a string we'll use to insert into the DB
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";                        //connection info for the DB
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
            preparedStatement.setString(1, name);
            preparedStatement.executeQuery();
            ResultSet rs = preparedStatement.executeQuery();

            Statement st = conn.createStatement();
            //pushing the INSERT command to the DB    

            while (rs.next()) {
                //System.out.println("| " + rs.getString(1) + "| " + rs.getLong(2) + " | " + rs.getLong(3) + " | " + rs.getString(4) + " |");   //id first last ssn phone
                System.out.println("|      " + rs.getString(1) + "     |        " + rs.getLong(2) + "           |      " + rs.getLong(3) + "      |");
            }

            System.out.print("__________________________________________________\n");
            conn.close();                                                                                              //closing the connection                
        } //CATCH STATEMENT INCASE OF AN ERROR//
        catch (Exception e) {
            System.err.println("There was an error!\n\n");
            //TRY STATEMENT TO CREATE ERROR LOG FILE//
            try {
                File f = new File("error_log.txt");                                  //attempting to create the log file
                if (f.exists()) {
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                            //creating a string with the current date and time
                    Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: SEARCH FOR DATA FROM worker_tbl(search_last method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                } else {
                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                    myfile.print("Error generated at: SEARCH FOR DATA FROM worker_tbl(search_last method)  <" + timeStamp + ">");     //printing what method had an error
                    myfile.close();
                }
            } //CATCH STATEMENT IF FILE CREATIONG FAILED//
            catch (IOException b) {
                System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
            }
        }
        main(null);

    }
//-------------------//

//METHOD TO GET HISTORY//
    public static void get_history() {
        //GETTING LAST NAME//
        Scanner user_input = new Scanner(System.in);
        System.out.print("Enter the name of the train: ");                                    //input check 
        Pattern valid_name = Pattern.compile("[aA-zZ]*");                             //kleen
        //while loop until user enters valid info
        while (!user_input.hasNext(valid_name)) {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the name of the train: ");
            user_input.next();
        }
        String name = user_input.next();
        //--------------//

        //TRY STATEMENT TO SELECT DATA FROM THE DB//
        try {
            System.out.print("\n\n");
            System.out.print("| Train name | Arrival time | Origin | Destination |\n");
            System.out.print("__________________________________________________\n");
            String sql = "SELECT * FROM history_tbl WHERE train_name=?";  //creating a string we'll use to insert into the DB
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";                        //connection info for the DB
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);                                         //prepared statement
            preparedStatement.setString(1, name);
            preparedStatement.executeQuery();
            ResultSet rs = preparedStatement.executeQuery();

            Statement st = conn.createStatement();
            
            //loop to print history info
            while (rs.next()) {
                System.out.println("|      " + rs.getString(1) + "     |  " + rs.getString(2) + "    |    " + rs.getLong(3) + "   |     " + rs.getLong(4));
            }

            System.out.print("__________________________________________________\n");
            conn.close();                                                                                              //closing the connection                
        } //CATCH STATEMENT INCASE OF AN ERROR//
        catch (Exception e) {
            System.err.println("There was an error!\n\n");
            //TRY STATEMENT TO CREATE ERROR LOG FILE//
            try {
                File f = new File("error_log.txt");                                  //attempting to create the log file
                if (f.exists()) {
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                            //creating a string with the current date and time
                    Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: SEARCH FOR DATA FROM history(history_tbl) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                } else {
                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                    myfile.print("Error generated at: SEARCH FOR DATA FROM history(history_tbl)  <" + timeStamp + ">");     //printing what method had an error
                    myfile.close();
                }
            } //CATCH STATEMENT IF FILE CREATIONG FAILED//
            catch (IOException b) {
                System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
            }
        }
        main(null);

    }
//-------------------//

//METHOD TO ADD A STOP//
    public static void add_stop() {

        //GETTING LAST NAME//
        Scanner user_input = new Scanner(System.in);
        System.out.print("Enter the stop number that the new stop will come after: ");                                    //input check 
        Pattern valid_name = Pattern.compile("[0-9]*");                             //kleen
        while (!user_input.hasNext(valid_name)) {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the stop number that the new stop will come after: ");                                    //input check
            user_input.next();
        }
        String stop_number = user_input.next();
        int stop_int = Integer.parseInt(stop_number);
        //--------------//

        //TRY STATEMENT TO INSERT DATA INTO THE DB//
        try {
            System.out.print("\n\n");
            System.out.print("| Searching for your stop...|\n");
            System.out.print("__________________________________________________\n");
            String sql = "SELECT * FROM stops_tbl WHERE stop_number=?";  //creating a string we'll use to insert into the DB
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";                        //connection info for the DB
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement
            preparedStatement.setString(1, stop_number);
            preparedStatement.executeQuery();
            ResultSet rs = preparedStatement.executeQuery();

            Statement st = conn.createStatement();
            //pushing the INSERT command to the DB 

            int rows = 0;
            while (rs.next()) {

//System.out.println("| " + rs.getString(1) + "| " + rs.getLong(2) + " | " + rs.getLong(3) + " | " + rs.getString(4) + " |");   //id first last ssn phone
                //long compare;
                //compare=rs.getLong(1);
                //check if the stop they want to place after exists
                if (rs.getLong(1) == stop_int) {
                    rows++;
                    System.out.println("Stop found\n");
                    long tmp_time = rs.getLong(3);
                    int tmp_stop = rs.getInt(2); //store next stop from previous stop

                    System.out.print("Enter the number of the next stop: ");                                    //input check 
                    Pattern valid_stop = Pattern.compile("[0-9]*");                             //kleen
                    while (!user_input.hasNext(valid_stop)) {
                        System.out.print("-Invalid Input-\n");
                        System.out.print("Enter the number of the next stop: ");                                    //input check 
                        user_input.next();
                    }
                    String new_stop = user_input.next();

                    Class.forName(myDriver);
                
                    PreparedStatement preparedStatement2 = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                    preparedStatement2.setString(1, new_stop);
                    preparedStatement2.executeQuery();
                    ResultSet rs2 = preparedStatement2.executeQuery();
                    int new_stop_long = Integer.parseInt(new_stop);
                    while (rs2.next()) {
                        if (rs2.getLong(1) == new_stop_long) {
                            System.out.print("This stop already exists\n");
                            main(null);
                        }
                    }

                    // Scanner user_input = new Scanner(System.in); 
                    System.out.print("Enter the transit timem in second from the previous stop to the new stop: ");                                    //input check 
                    Pattern valid_time = Pattern.compile("[0-9]*");                             //kleen
                    while (!user_input.hasNext(valid_time)) {
                        System.out.print("-Invalid Input-\n");
                        System.out.print("Enter the transit timem in seconds from the previous stop to the new stop: ");                                    //input check 
                        user_input.next();
                    }
                    String time_from_old = user_input.next();
                    int previous_to_new_int = Integer.parseInt(time_from_old);

                    // Scanner user_input = new Scanner(System.in); 
                    System.out.print("Enter the transit timem in second from the new stop to the next stop: ");                                    //input check
                    Pattern valid_time_to_previous = Pattern.compile("[0-9]*");                             //kleen
                    while (!user_input.hasNext(valid_time)) {
                        System.out.print("-Invalid Input-\n");
                        System.out.print("Enter the transit timem in second from the new stop to the next stop: ");                                    //input check 
                        user_input.next();
                    }
                    String new_to_next = user_input.next();
                    int new_to_next_int = Integer.parseInt(new_to_next);

                    String update_query = "update stops_tbl set next_stop=?,traverse_time=? where stop_number=?";

                    // create the mysql insert preparedstatement
                    PreparedStatement preparedStmt = conn.prepareStatement(update_query);
                    preparedStmt.setString(1, new_stop);
                    preparedStmt.setInt(2, previous_to_new_int);
                    preparedStmt.setInt(3, stop_int);

                    String query = " insert into stops_tbl (stop_number, next_stop, traverse_time)"
                            + " values (?, ?, ?)";

                    // create the mysql insert preparedstatement
                    PreparedStatement preparedStmt3 = conn.prepareStatement(query);
                    preparedStmt3.setInt(1, new_stop_long);
                    preparedStmt3.setInt(2, tmp_stop);
                    preparedStmt3.setInt(3, new_to_next_int);

                    // execute the preparedstatement
                    preparedStmt.execute();

                    // execute the preparedstatement
                    preparedStmt3.execute();

                    //--------------//
                }

            }

            if (rows == 0) {
                System.out.println("Stop not found, exiting to main menu");
            }
            System.out.print("__________________________________________________\n");
            conn.close();                                                                                              //closing the connection                
        } //CATCH STATEMENT INCASE OF AN ERROR//
        catch (Exception e) {
            System.err.println("There was an error!\n\n");
            //TRY STATEMENT TO CREATE ERROR LOG FILE//
            try {
                File f = new File("error_log.txt");                                  //attempting to create the log file
                if (f.exists()) {
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                            //creating a string with the current date and time
                    Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: INSERT INTO stop_tbl(stops_tbl) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                } else {
                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                    myfile.print("Error generated at: INSERT INTO stop_tbl(stops_tbl)  <" + timeStamp + ">");     //printing what method had an error
                    myfile.close();
                }
            } //CATCH STATEMENT IF FILE CREATIONG FAILED//
            catch (IOException b) {
                System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
            }
        }
        main(null);

    }
//-------------------//

//METHOD TO DELETE A STOP//
    public static void delete_stop() {
        //GETTING LAST NAME//
        Scanner user_input = new Scanner(System.in);
        System.out.print("Enter the stop number to delete: ");                                    //input check 
        Pattern valid_name = Pattern.compile("[0-9]*");                             //kleen
        while (!user_input.hasNext(valid_name)) {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the stop number to delete: ");                                    //input check
            user_input.next();
        }
        String stop_number = user_input.next();
        int stop_int = Integer.parseInt(stop_number);
        //--------------//

//TRY STATEMENT TO SELECT//
        try {
            System.out.print("\n\n");
            System.out.print("| Searching for your stop...|\n");
            System.out.print("__________________________________________________\n");
            String sql = "SELECT * FROM stops_tbl WHERE stop_number=?";  //creating a string we'll use to select
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";                        //connection info for the DB
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
            preparedStatement.setString(1, stop_number);
            preparedStatement.executeQuery();
            ResultSet rs = preparedStatement.executeQuery();

            Statement st = conn.createStatement();

            int rows = 0;
            while (rs.next()) {

                if (rs.getLong(1) == stop_int) {
                    rows++;
                    System.out.println("Stop found...\nDeleting stop...\n");

                    int next_stop = rs.getInt(2);     //saving next stop of the stop we are deleting
                    int time = rs.getInt(3);            //saving time to next stop of the stop we are deleting

                    String next_stop_string = Integer.toString(next_stop);
                    String time_string = Integer.toString(time);

                    String sql2 = "SELECT * FROM stops_tbl WHERE next_stop=?";  //creating a string we'll use to insert into the DB
                    // String myDriver = "org.gjt.mm.mysql.Driver";
                    //String myUrl = "jdbc:mysql://68.188.20.101:3306/trains2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                    Class.forName(myDriver);
                    //Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                    PreparedStatement preparedStatement2 = conn.prepareStatement(sql2);                                          //prepared statement to insert info into table
                    preparedStatement2.setString(1, stop_number);
                    preparedStatement2.executeQuery();
                    ResultSet rs2 = preparedStatement2.executeQuery();
                    //int new_stop_long=Integer.parseInt(new_stop);
                    while (rs2.next()) {
                        if (rs2.getLong(2) == stop_int) {
                            int new_time = rs2.getInt(3);

                            String update_query = "update stops_tbl set next_stop=?,traverse_time=? where next_stop=?";

                            // create the mysql insert preparedstatement
                            PreparedStatement preparedStmt = conn.prepareStatement(update_query);
                            preparedStmt.setString(1, next_stop_string);
                            preparedStmt.setInt(2, time + new_time);
                            preparedStmt.setInt(3, stop_int);

                            // execute the preparedstatement
                            preparedStmt.execute();
                        }
                    }

                   
                    Class.forName(myDriver);
                  
                    String query = "delete from stops_tbl where stop_number = ?";
                    PreparedStatement preparedStmt = conn.prepareStatement(query);
                    preparedStmt.setInt(1, stop_int);
                    preparedStmt.execute();
                    //--------------//
                }

            }

            if (rows == 0) {
                System.out.println("Stop not found, exiting to main menu");
            }
            System.out.print("__________________________________________________\n");
            conn.close();                                                                                              //closing the connection                
        } catch (Exception a) {
            System.out.println("Error");
        }
        main(null);
    }
//----------------------//

}
