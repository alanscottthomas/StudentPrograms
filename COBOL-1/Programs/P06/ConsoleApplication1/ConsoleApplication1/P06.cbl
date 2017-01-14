       identification division.
       program-id. TRIG-CALC.
       author. Alan Thomas.
       date-compiled. 10/26/2015.
      *function: Accept and compute/display SINE,COSINE & TANGENT
      *input files None
      *output files None
      *printer ouput None



       data division.
       working-storage section.
       01 DEGREE              PIC S9(3).
       01 RADIAN              PIC z(2)V9(4).
       01 SINE_PRINT          PIC s9(1)V9(4).
       01 COSINE_PRINT        PIC S9(1)V9(4).
       01 TANGENT_PRINT       PIC S9(1)V9(4).
       01 SWITCH              PIC x           VALUE "N".
       01 X                   PIC X(1).

       procedure division.

       000-MAIN.
         PERFORM 100-DEGREE
               UNTIL SWITCH = 'Y'.
           DISPLAY "-EXITING PROGRAM-".
           STOP RUN.

      *-BEGIN CODE TO ACCEPT AND DISPLAY USER INPUT-
       100-DEGREE.
           DISPLAY "-----------------".
           DISPLAY "Enter angle in degree (1-360)(0 to exit): ".
           ACCEPT DEGREE.

           IF DEGREE = 0 *>Checking PRICE for LOOOP SWITCH
               MOVE 'Y' TO SWITCH

           ELSE IF DEGREE > 360 OR 0 > DEGREE
               DISPLAY "*INVALID DEGREE ENTERED*"
               PERFORM 000-MAIN

      *-RUNNING FUNCTIONS FOR TRIG CALCS-
           ELSE
               MULTIPLY DEGREE BY 0.017463292 GIVING RADIAN ROUNDED
               COMPUTE SINE_PRINT = FUNCTION SIN (RADIAN)
               COMPUTE COSINE_PRINT = FUNCTION COS (RADIAN)
               COMPUTE TANGENT_PRINT = FUNCTION TAN (RADIAN)
               DISPLAY "SINE:   ",SINE_PRINT
               DISPLAY "COSINE: ",COSINE_PRINT
               DISPLAY "TANGENT: ",TANGENT_PRINT
          END-IF.

       end program TRIG-CALC.
