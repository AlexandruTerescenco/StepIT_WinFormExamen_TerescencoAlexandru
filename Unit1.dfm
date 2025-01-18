object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 766
  ClientWidth = 1032
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  StyleName = 'Cobalt XEMedia'
  OnActivate = FormActivate
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1032
    Height = 766
    ActivePage = AUTENTIFICARE
    Align = alClient
    TabOrder = 0
    StyleName = 'Cobalt XEMedia'
    ExplicitLeft = -8
    object AUTENTIFICARE: TTabSheet
      Caption = 'AUTENTIFICARE'
      object Panel5: TPanel
        Left = 232
        Top = 192
        Width = 500
        Height = 250
        TabOrder = 0
        object SpeedButton21: TSpeedButton
          Left = 176
          Top = 168
          Width = 250
          Height = 50
          Caption = 'Autentificare'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold]
          ParentFont = False
          OnClick = SpeedButton21Click
        end
        object Edit13: TEdit
          Left = 176
          Top = 40
          Width = 250
          Height = 38
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          TextHint = 'Nume Utilizator'
        end
        object Edit14: TEdit
          Left = 176
          Top = 96
          Width = 250
          Height = 38
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold]
          ParentFont = False
          PasswordChar = '*'
          TabOrder = 1
          TextHint = 'Parola'
        end
      end
    end
    object STUDENT: TTabSheet
      Caption = 'STUDENT'
      ImageIndex = 1
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 210
        Height = 736
        Align = alLeft
        TabOrder = 0
        StyleName = 'Cobalt XEMedia'
        object PageControl3: TPageControl
          Left = 1
          Top = 1
          Width = 208
          Height = 734
          ActivePage = SINSERARE
          Align = alClient
          TabHeight = 1
          TabOrder = 0
          TabWidth = 1
          StyleName = 'Cobalt XEMedia'
          object SMAIN: TTabSheet
            Caption = 'SMAIN'
            object SpeedButton12: TSpeedButton
              Left = 15
              Top = 544
              Width = 175
              Height = 50
              Caption = 'ELIMINA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton1Click
            end
            object SpeedButton13: TSpeedButton
              Left = 15
              Top = 488
              Width = 175
              Height = 50
              Caption = 'EDITEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton13Click
            end
            object SpeedButton14: TSpeedButton
              Left = 15
              Top = 432
              Width = 175
              Height = 50
              Caption = 'INSERARE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton14Click
            end
            object SpeedButton15: TSpeedButton
              Left = 15
              Top = 40
              Width = 175
              Height = 50
              Caption = 'SELECTEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object SpeedButton16: TSpeedButton
              Left = 15
              Top = 96
              Width = 175
              Height = 50
              Caption = 'ANULEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
            end
          end
          object SINSERARE: TTabSheet
            Caption = 'SINSERARE'
            ImageIndex = 1
            object SpeedButton8: TSpeedButton
              Left = 9
              Top = 440
              Width = 175
              Height = 50
              Caption = 'INSEREAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton8Click
            end
            object SpeedButton9: TSpeedButton
              Left = 9
              Top = 520
              Width = 175
              Height = 50
              Caption = 'ANULARE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton9Click
            end
            object Edit3: TEdit
              Left = 0
              Top = 19
              Width = 200
              Height = 23
              TabOrder = 0
              TextHint = 'NUME'
            end
            object Edit4: TEdit
              Left = -1
              Top = 48
              Width = 200
              Height = 23
              TabOrder = 1
              TextHint = 'PRENUME'
            end
            object Edit5: TEdit
              Left = -1
              Top = 77
              Width = 200
              Height = 23
              TabOrder = 2
              TextHint = 'GRUPA'
            end
            object Edit6: TEdit
              Left = -3
              Top = 179
              Width = 200
              Height = 23
              NumbersOnly = True
              TabOrder = 3
              TextHint = 'IDNP'
            end
            object Edit7: TEdit
              Left = -3
              Top = 208
              Width = 200
              Height = 23
              NumbersOnly = True
              TabOrder = 4
              TextHint = 'TELEFON'
            end
            object DateTimePicker1: TDateTimePicker
              Left = 0
              Top = 120
              Width = 200
              Height = 23
              Date = 45227.000000000000000000
              Time = 0.428863090281083700
              TabOrder = 5
            end
            object ComboBox1: TComboBox
              Left = 0
              Top = 150
              Width = 200
              Height = 23
              TabOrder = 6
              TextHint = 'GEN'
              Items.Strings = (
                'FEMININ'
                'MASCULIN')
            end
          end
          object SEDITARE: TTabSheet
            Caption = 'SEDITARE'
            ImageIndex = 2
            object SpeedButton17: TSpeedButton
              Left = 14
              Top = 528
              Width = 175
              Height = 50
              Caption = 'ANULARE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton9Click
            end
            object SpeedButton18: TSpeedButton
              Left = 14
              Top = 448
              Width = 175
              Height = 50
              Caption = 'EDITEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton18Click
            end
            object Edit2: TEdit
              Left = 0
              Top = 91
              Width = 200
              Height = 23
              TabOrder = 0
              TextHint = 'GRUPA'
            end
            object Edit8: TEdit
              Left = 0
              Top = 216
              Width = 200
              Height = 23
              NumbersOnly = True
              TabOrder = 1
              TextHint = 'TELEFON'
            end
            object Edit10: TEdit
              Left = -3
              Top = 187
              Width = 200
              Height = 23
              NumbersOnly = True
              TabOrder = 2
              TextHint = 'IDNP'
            end
            object Edit11: TEdit
              Left = 0
              Top = 27
              Width = 200
              Height = 23
              TabOrder = 3
              TextHint = 'NUME'
            end
            object ComboBox2: TComboBox
              Left = 0
              Top = 158
              Width = 200
              Height = 23
              ItemIndex = 0
              TabOrder = 4
              TextHint = 'GEN'
              Items.Strings = (
                'FEMININ'
                'MASCULIN')
            end
            object DateTimePicker2: TDateTimePicker
              Left = 0
              Top = 128
              Width = 200
              Height = 23
              Date = 45227.000000000000000000
              Time = 0.428863090281083700
              TabOrder = 5
            end
            object Edit12: TEdit
              Left = 0
              Top = 56
              Width = 200
              Height = 23
              TabOrder = 6
              TextHint = 'PRENUME'
            end
          end
        end
      end
      object Panel4: TPanel
        Left = 210
        Top = 0
        Width = 814
        Height = 736
        Align = alClient
        TabOrder = 1
        StyleName = 'Cobalt XEMedia'
        object DBGrid2: TDBGrid
          Left = 1
          Top = 1
          Width = 812
          Height = 734
          Align = alClient
          DataSource = DataModule2.DSQSTUDENT
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -12
          TitleFont.Name = 'Segoe UI'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'NUME'
              Title.Alignment = taCenter
              Width = 92
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'PRENUME'
              Title.Alignment = taCenter
              Width = 119
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DATA_NASTERII'
              Title.Alignment = taCenter
              Width = 95
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'GEN'
              Title.Alignment = taCenter
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'NUME_1'
              Title.Alignment = taCenter
              Title.Caption = 'GRUPA'
              Width = 85
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'IDNP'
              Title.Alignment = taCenter
              Width = 87
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'TELEFON'
              Title.Alignment = taCenter
              Width = 129
              Visible = True
            end>
        end
      end
    end
    object GRUPA: TTabSheet
      Caption = 'GRUPA'
      ImageIndex = 2
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 210
        Height = 736
        Align = alLeft
        TabOrder = 0
        StyleName = 'Cobalt XEMedia'
        object PageControl2: TPageControl
          Left = 1
          Top = 1
          Width = 208
          Height = 734
          ActivePage = GEDITARE
          Align = alClient
          TabHeight = 1
          TabOrder = 0
          TabWidth = 1
          StyleName = 'Cobalt XEMedia'
          object GMAIN: TTabSheet
            Caption = 'GMAIN'
            object SpeedButton1: TSpeedButton
              Left = 16
              Top = 536
              Width = 175
              Height = 50
              Caption = 'ELIMINA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton1Click
            end
            object SpeedButton2: TSpeedButton
              Left = 16
              Top = 480
              Width = 175
              Height = 50
              Caption = 'EDITEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton2Click
            end
            object SpeedButton3: TSpeedButton
              Left = 16
              Top = 424
              Width = 175
              Height = 50
              Caption = 'INSERARE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton3Click
            end
            object SpeedButton6: TSpeedButton
              Left = 16
              Top = 32
              Width = 175
              Height = 50
              Caption = 'SELECTEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object SpeedButton7: TSpeedButton
              Left = 16
              Top = 96
              Width = 175
              Height = 50
              Caption = 'ANULEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
            end
          end
          object GINSERARE: TTabSheet
            Caption = 'GINSERARE'
            ImageIndex = 1
            object SpeedButton4: TSpeedButton
              Left = 14
              Top = 416
              Width = 175
              Height = 50
              Caption = 'INSEREAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton4Click
            end
            object SpeedButton5: TSpeedButton
              Left = 14
              Top = 496
              Width = 175
              Height = 50
              Caption = 'ANULARE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton5Click
            end
            object Edit1: TEdit
              Left = -1
              Top = 16
              Width = 200
              Height = 23
              TabOrder = 0
              TextHint = 'NUME'
            end
            object CSpinEdit1: TCSpinEdit
              Left = -1
              Top = 45
              Width = 200
              Height = 24
              MaxValue = 3000
              MinValue = 2000
              TabOrder = 1
            end
          end
          object GEDITARE: TTabSheet
            Caption = 'GEDITARE'
            ImageIndex = 2
            object SpeedButton10: TSpeedButton
              Left = 14
              Top = 496
              Width = 175
              Height = 50
              Caption = 'ANULARE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton5Click
            end
            object SpeedButton11: TSpeedButton
              Left = 14
              Top = 424
              Width = 175
              Height = 50
              Caption = 'EDITEAZA'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Segoe UI'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = SpeedButton11Click
            end
            object Edit9: TEdit
              Left = 0
              Top = 24
              Width = 200
              Height = 23
              TabOrder = 0
              TextHint = 'NUME'
            end
            object CSpinEdit2: TCSpinEdit
              Left = 0
              Top = 53
              Width = 200
              Height = 24
              MaxValue = 3000
              MinValue = 2000
              TabOrder = 1
            end
          end
        end
      end
      object Panel2: TPanel
        Left = 210
        Top = 0
        Width = 814
        Height = 736
        Align = alClient
        TabOrder = 1
        StyleName = 'Cobalt XEMedia'
        object DBGrid1: TDBGrid
          Left = 1
          Top = 1
          Width = 812
          Height = 734
          Align = alClient
          DataSource = DataModule2.DSQGRUPA
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -12
          TitleFont.Name = 'Segoe UI'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'GRUPA_ID'
              Title.Alignment = taCenter
              Title.Caption = 'GRUPA ID'
              Width = 95
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'NUME'
              Title.Alignment = taCenter
              Width = 114
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'AN_FORMARE'
              Title.Alignment = taCenter
              Title.Caption = 'AN FORMARE'
              Width = 143
              Visible = True
            end>
        end
      end
    end
  end
end
