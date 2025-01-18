object DataModule2: TDataModule2
  Height = 694
  Width = 791
  object BAZA: TFDConnection
    Params.Strings = (
      'DataSource=STUDO'
      'DriverID=ODBC')
    Connected = True
    LoginPrompt = False
    Left = 104
    Top = 88
  end
  object QSTUDENT: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'SELECT STUDENT_ID, S.NUME,PRENUME,G.NUME,DATA_NASTERII,GEN,IDNP,' +
        'TELEFON '
      'FROM STUDENT S INNER JOIN GRUPA G ON S.GRUPA_ID = G.GRUPA_ID ')
    Left = 184
    Top = 88
  end
  object DSQSTUDENT: TDataSource
    DataSet = QSTUDENT
    Left = 280
    Top = 88
  end
  object QGRUPA: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'SELECT * FROM GRUPA')
    Left = 184
    Top = 168
  end
  object DSQGRUPA: TDataSource
    DataSet = QGRUPA
    Left = 280
    Top = 168
  end
  object QGINSERT: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'INSERT INTO GRUPA(NUME,AN_FORMARE)'
      'VALUES (:NUME, :AN_FORMARE)')
    Left = 120
    Top = 264
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'AN_FORMARE'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object QGDELETE: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'DELETE GRUPA WHERE GRUPA_ID = :ID')
    Left = 120
    Top = 416
    ParamData = <
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object QSINSERT: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'INSERT INTO STUDENT(NUME,PRENUME,DATA_NASTERII,GRUPA_ID,GEN,IDNP' +
        ',TELEFON)'
      
        'VALUES(:NUME,:PRENUME,:DATA_NASTERII,(SELECT GRUPA_ID FROM GRUPA' +
        ' WHERE NUME =:GNUME),:GEN,:IDNP,:TELEFON)')
    Left = 248
    Top = 264
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PRENUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'DATA_NASTERII'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GNUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GEN'
        DataType = ftBoolean
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'IDNP'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'TELEFON'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end>
  end
  object QSDELETE: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'DELETE STUDENT WHERE STUDENT_ID = :ID')
    Left = 248
    Top = 416
    ParamData = <
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object QGEDIT: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      'UPDATE GRUPA SET NUME =:NUME, AN_FORMARE =:AN_FORMARE'
      'WHERE GRUPA_ID =:ID')
    Left = 120
    Top = 336
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'AN_FORMARE'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object QSEDIT: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'UPDATE STUDENT SET NUME =:NUME, PRENUME = :PRENUME,DATA_NASTERII' +
        ' =:DATA_NASTERII,'
      
        'GRUPA_ID = (SELECT GRUPA_ID FROM GRUPA WHERE NUME =:GNUME),GEN =' +
        ' :GEN, IDNP =:IDNP, TELEFON =:TELEFON'
      'WHERE STUDENT_ID =:ID ')
    Left = 248
    Top = 336
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PRENUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'DATA_NASTERII'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GNUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GEN'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'IDNP'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'TELEFON'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object QSG: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'SELECT G.NUME FROM GRUPA G INNER JOIN STUDENT S ON G.GRUPA_ID = ' +
        'S.GRUPA_ID'
      'WHERE STUDENT_ID = ID')
    Left = 344
    Top = 264
  end
  object QAUTENTIFICARE: TFDQuery
    Connection = BAZA
    SQL.Strings = (
      
        'SELECT * FROM OPERATOR WHERE USERNAME =:USERNAME AND PAROLA =:PA' +
        'ROLA ')
    Left = 424
    Top = 88
    ParamData = <
      item
        Name = 'USERNAME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PAROLA'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end>
  end
end
