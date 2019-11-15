LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;
USE work.my_package.ALL;
USE work.math_real.ALL;

ENTITY InstrMem IS
   PORT( 
      A     : IN  std_logic_vector (n_bits_address - 1 DOWNTO 0);
      rst   : IN  std_logic;
      Instr : OUT std_logic_vector (instr_mem_width - 1 DOWNTO 0)
   );
END InstrMem;

ARCHITECTURE behav OF InstrMem IS

   -- Internal signal declarations
   SIGNAL instr_mem  : mem_type(0 to instr_mem_depth - 1);
   SIGNAL A_index : std_logic_vector (A'length - 1 DOWNTO 0);

BEGIN

   -- Address guard for read port
   A_index <= A WHEN ((TO_INTEGER(UNSIGNED(A)) >= TO_INTEGER(UNSIGNED(text_segment_start))) AND (TO_INTEGER(UNSIGNED(A)) < (TO_INTEGER(UNSIGNED(text_segment_start)) + data_mem_depth))) ELSE (text_segment_start);
   
   ---------------------------------------------------------------------------
   read_process : PROCESS (A_index, rst)
   ---------------------------------------------------------------------------
   BEGIN
      -- Asynchronous Reset
      IF (rst = '1') THEN
         -- Reset Actions
         instr_mem <= my_program;
         Instr <= zeros;
      ELSE
         Instr <= instr_mem(TO_INTEGER(UNSIGNED(A_index)));
      END IF;
   END PROCESS read_process;

END behav;
