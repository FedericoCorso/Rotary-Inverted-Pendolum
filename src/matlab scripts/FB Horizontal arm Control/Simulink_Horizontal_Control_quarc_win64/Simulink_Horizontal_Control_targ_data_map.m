  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Simulink_Horizontal_Control_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_P.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_P.B
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 16;
	
	  ;% Simulink_Horizontal_Control_P.C
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 20;
	
	  ;% Simulink_Horizontal_Control_P.theta_max
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 36;
	
	  ;% Simulink_Horizontal_Control_P.voltage_max
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_P.Encoders_clock
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_P.Encoders_channels
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_P.Voltage_channels
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Simulink_Horizontal_Control_P.Encoders_samples_in_buffer
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_AOFinal
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_POFinal
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Simulink_Horizontal_Control_P.Gain1_Gain
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Simulink_Horizontal_Control_P.Offset_Value
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Simulink_Horizontal_Control_P.StateSpace_InitialCondition
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Simulink_Horizontal_Control_P.Offset_Value_d
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Simulink_Horizontal_Control_P.Referencethetarad_Amplitude
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Simulink_Horizontal_Control_P.Referencethetarad_Frequency
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Simulink_Horizontal_Control_P.SineWave_Amp
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Simulink_Horizontal_Control_P.SineWave_Bias
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Simulink_Horizontal_Control_P.SineWave_Freq
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Simulink_Horizontal_Control_P.SineWave_Phase
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Simulink_Horizontal_Control_P.Gain_Gain
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Simulink_Horizontal_Control_P.Internal_A
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Simulink_Horizontal_Control_P.Internal_B
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 24;
	
	  ;% Simulink_Horizontal_Control_P.Internal_C
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 25;
	
	  ;% Simulink_Horizontal_Control_P.Internal_InitialCondition
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 29;
	
	  ;% Simulink_Horizontal_Control_P.Gain_Gain_g
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 30;
	
	  ;% Simulink_Horizontal_Control_P.Gain2_Gain
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 31;
	
	  ;% Simulink_Horizontal_Control_P.Gain_Gain_m
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 32;
	
	  ;% Simulink_Horizontal_Control_P.Internal_A_p
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 33;
	
	  ;% Simulink_Horizontal_Control_P.Internal_B_n
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 42;
	
	  ;% Simulink_Horizontal_Control_P.Internal_C_n
	  section.data(25).logicalSrcIdx = 33;
	  section.data(25).dtTransOffset = 43;
	
	  ;% Simulink_Horizontal_Control_P.Internal_InitialCondition_j
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_P.ToHostFile_Decimation
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_P.ToHostFile_BitRate
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 42;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 43;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Simulink_Horizontal_Control_P.HILInitialize_DOFinal
	  section.data(8).logicalSrcIdx = 44;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Simulink_Horizontal_Control_P.Encoders_Active
	  section.data(9).logicalSrcIdx = 45;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Simulink_Horizontal_Control_P.Voltage_Active
	  section.data(10).logicalSrcIdx = 46;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_P.ToHostFile_file_name
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Simulink_Horizontal_Control_P.ToHostFile_VarName
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 31;
	
	  ;% Simulink_Horizontal_Control_P.ToHostFile_FileFormat
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Simulink_Horizontal_Control_B)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_B.alpharad
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_B.StateSpace
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Simulink_Horizontal_Control_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Simulink_Horizontal_Control_B.Referencetheta
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Simulink_Horizontal_Control_B.thetarad
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Simulink_Horizontal_Control_B.error
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Simulink_Horizontal_Control_B.error_a
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Simulink_Horizontal_Control_B.Internal
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% Simulink_Horizontal_Control_B.Gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% Simulink_Horizontal_Control_B.Switch1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% Simulink_Horizontal_Control_B.Gain2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% Simulink_Horizontal_Control_B.Switch1_m
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Simulink_Horizontal_Control_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_DW.HILInitialize_AOVoltages
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_DW.Encoders_Task
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_DW.Alpharealvssimulated_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_DW.Error_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Simulink_Horizontal_Control_DW.Error1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Simulink_Horizontal_Control_DW.Inputvoltage_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Simulink_Horizontal_Control_DW.Realoutput_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Simulink_Horizontal_Control_DW.ReferecnevsRealTheta_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Simulink_Horizontal_Control_DW.Scope_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Simulink_Horizontal_Control_DW.Thetarealvssimulated_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 10;
	
	  ;% Simulink_Horizontal_Control_DW.ToHostFile_PWORK
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Simulink_Horizontal_Control_DW.Voltage_PWORK
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_DW.Encoders_Buffer
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Simulink_Horizontal_Control_DW.ToHostFile_SamplesCount
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Simulink_Horizontal_Control_DW.ToHostFile_ArrayNameLength
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3830886438;
  targMap.checksum1 = 629539251;
  targMap.checksum2 = 4123486669;
  targMap.checksum3 = 3817867681;

