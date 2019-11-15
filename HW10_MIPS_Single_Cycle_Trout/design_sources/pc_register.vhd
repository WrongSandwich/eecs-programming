LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE work.my_package.ALL;
USE work.math_real.ALL;


ENTITY PC_register IS
   PORT( 
      PC_next    : IN     std_logic_vector (n_bits_address - 1 DOWNTO 0);
      clk        : IN     std_logic;
      rst        : IN     std_logic;
      PC_current : OUT    std_logic_vector (n_bits_address - 1 DOWNTO 0)
   );
END PC_register;


ARCHITECTURE behav OF PC_register IS

BEGIN
    
    pc_process : PROCESS (clk, rst)
    BEGIN
        IF (rst = '1') THEN
            PC_current <= x"00400000"; -- obviously this needs to be something else, text segment start?
        ELSIF (clk'EVENT AND clk = '1') THEN
            PC_current <= PC_next;
        END IF;
    END PROCESS pc_process;
END behav;
