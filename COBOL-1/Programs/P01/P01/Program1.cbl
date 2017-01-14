       identification division.
       program-id. SALES-TAX.
       author. Alan Thomas.
       date-compiled. 9/11/2015.
      *function. Accept and compute/display sales tax
      *input files None
      *output files None
      *printer ouput None
      *Remarks: I had difficulty displaying information in a format that I found acceptable.
      *I wasn't having any luck using the z switch in the picture without getting an error saying that the picture needed to be an integer.
      *From what I gathered after read is that you have to have a seperate data variable established and save the computations to that variable
      *Doing this will allow you to truncate zeroes and handle the data in a matter you find more fitting. Probably not the best way to do things,
      *but I'm sure I'll learn more effecient ways as the semester progresses.

       data division.
       working-storage section.
      *Made multiples of names in order to be able to truncate zeroes and make it more asthetically pleasing to the user.
       01  TAX-PERCENTAGE      PIC 99V99.
       01  TAX-PERCENTAGE-X    PIC V9999.
       01  TAX-PERCENTAGE-X1   PIC z(6).99.
       01  PRICE               PIC 9(6)V99.
       01  PRICE-X             PIC Z(6).99.
       01  SALES-TAX           PIC Z(6).99.
       01  TOTAL               PIC Z(6).99.
       01  SWITCH              PIC x           VALUE "N".
       
       
       procedure division.
       
       000-MAIN.
          DISPLAY "   | |". 
          DISPLAY "  / __)".
          DISPLAY "  \__ \  Tax Calculator 3000".
          DISPLAY "  (   /       Coded by Alan Thomas".
          DISPLAY "   |_|".
          DISPLAY "".
          DISPLAY "Enter the sales tax (ex. 9.8 is 9.8%): ". 
          ACCEPT TAX-PERCENTAGE.
          MOVE TAX-PERCENTAGE TO TAX-PERCENTAGE-X1.
         
         PERFORM 100-TAXCALC
               UNTIL SWITCH = 'Y'.
           DISPLAY "0 ENTERED - EXITING PROGRAM".
           STOP RUN.
      *Code starts here
       100-TAXCALC.
          
           DISPLAY "----------------------------------".
           DISPLAY "Enter sales price: ".
           ACCEPT PRICE.
      
           IF PRICE = 0 *>Checking PRICE for LOOOP SWITCH
               MOVE 'Y' TO SWITCH
   
           ELSE *>Converting tax into decimal  
               DIVIDE 100 into TAX-PERCENTAGE GIVING TAX-PERCENTAGE-X
      
                                                                  
      *        COMPUTE TAX-PERCENTAGE-X1  =           *>Used PRICE-X in order to be able to truncate zeros
      *            TAX-PERCENTAGE + 0
                                                  
      *        COMPUTE PRICE-X ROUNDED =              *>Computing and displaying the price  
      *            PRICE + 0
                                                                  
               COMPUTE TOTAL ROUNDED =                *>Computing and rounded total amount of the purchase     
                   PRICE + (PRICE * TAX-PERCENTAGE-X) 
               
      
               MULTIPLY PRICE BY TAX-PERCENTAGE-X GIVING SALES-TAX       *>Computing how much the tax will be
               
               MOVE PRICE TO PRICE-X
      
               DISPLAY "Sales Tax Percentage: %" TAX-PERCENTAGE-X1         *>Displaying information for the user 
               DISPLAY "               Price: $" PRICE-X
               DISPLAY "   Sales Tax Ammount: $" SALES-TAX
               DISPLAY "         Total Price: $" TOTAL
            END-IF.
       DISPLAY "EXIT DETECTED".
       ACCEPT SALES-TAX.
       end program SALES-TAX.
