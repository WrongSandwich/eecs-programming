LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;
USE work.my_package.ALL;
USE work.math_real.ALL;

ENTITY DataMem IS
   PORT( 
      A        : IN  std_logic_vector (n_bits_address - 1 DOWNTO 0);
      MemWrite : IN  std_logic;
      WD       : IN  std_logic_vector (data_mem_width - 1 DOWNTO 0);
      clk      : IN  std_logic;
      rst      : IN  std_logic;
      RD       : OUT std_logic_vector (data_mem_width - 1 DOWNTO 0)
   );
END DataMem;

ARCHITECTURE behav OF DataMem IS

   -- Internal signal declarations
   SIGNAL data_mem  : mem_type(0 to data_mem_depth - 1);
   SIGNAL A_index : std_logic_vector (A'length - 1 DOWNTO 0);

BEGIN

   -- Address guard for read port
   A_index <= A WHEN ((TO_INTEGER(UNSIGNED(A)) >= TO_INTEGER(UNSIGNED(data_segment_start))) AND (TO_INTEGER(UNSIGNED(A)) < TO_INTEGER(UNSIGNED(TOS)))) ELSE (data_segment_start);
   -- Multiplexer for read port
   RD <= data_mem(TO_INTEGER(UNSIGNED(A_index)));
   
   -- Write process that combines inferred registers, write-enable, and address guard for write operation
   ---------------------------------------------------------------------------
   write_process : PROCESS (clk, rst)
   ---------------------------------------------------------------------------
   BEGIN
      -- Asynchronous Reset
      IF (rst = '1') THEN
         -- Reset Actions
         data_mem <= initial_data_mem;
      ELSIF (clk'EVENT AND clk = '1') THEN -- inferred registers
         -- Write-enable, and address guard for write operation
         IF ((MemWrite = '1') AND ((TO_INTEGER(UNSIGNED(A)) >= 0) AND (TO_INTEGER(UNSIGNED(A)) < data_mem_depth))) THEN
            data_mem(TO_INTEGER(UNSIGNED(A))) <= WD;
         END IF;
      END IF;
   END PROCESS write_process;

END behav;
