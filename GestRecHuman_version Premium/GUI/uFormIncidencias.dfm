object FormIncidencias: TFormIncidencias
  Left = 110
  Top = 117
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Administraci'#243'n - Registros de Incidencias'
  ClientHeight = 315
  ClientWidth = 570
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    7777777777777777110000000110000078888888888888871111111111110000
    08777FFFFFF77780777777777771000000007777777700007777778888830777
    77777777722777227777777777837888888888882AA282AA2887778888837888
    8888888882288822888777777783788888888888888888888887778888837866
    6666666666666666668777777783780000000000000000000087778888877800
    0000000000000000008777777787780000000000000000000087778888877800
    0000000000000000008777888887780000FFFFFFFFFFFF000087777777877800
    00FF8888F8888F00008788888787780000FFFFFFFFFFFF000087888887877800
    00FFFFFFFFFFFF00008788FFF7F7780000FFFFFFFFFFFF00008788FFF7F77800
    00CCCCCCCCCCCC00008788FFB7F778000000000000000000008788FFF7F77800
    00000000000000000087777777F778000000000000000000008788FFF7F77800
    000000000000000000878FFFB7F7788888888888888888888887FFFFF7F70777
    77777777777777777777777777F700000000000000000007FFFFFFFFFFF70000
    0000000000000007FFFFFFFFFFF7000000000000000000007777777777700000
    000000000000000000000000000000000000000000000000000000000000FFFF
    FFFFFFFFFFFFF00003F9F0000000F8000000FF00E00080000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    00000000000080000000FFFFE000FFFFE000FFFFF001FFFFFFFFFFFFFFFF}
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel2: TBevel
    Left = 8
    Top = 5
    Width = 554
    Height = 276
  end
  object Label6: TLabel
    Left = 17
    Top = 15
    Width = 135
    Height = 13
    Caption = 'Seleccione el departamento:'
  end
  object GroupBox2: TGroupBox
    Left = 329
    Top = 64
    Width = 226
    Height = 161
    Caption = 'Indique las incidencias: '
    TabOrder = 5
    object Label2: TLabel
      Left = 66
      Top = 36
      Width = 62
      Height = 13
      Caption = 'Horas extras:'
    end
    object Label3: TLabel
      Left = 38
      Top = 76
      Width = 92
      Height = 13
      Caption = 'Horas de ausencia:'
    end
    object Label4: TLabel
      Left = 15
      Top = 116
      Width = 115
      Height = 13
      Caption = 'D'#237'as feriados laborados:'
    end
    object Edit1: TEdit
      Left = 135
      Top = 34
      Width = 74
      Height = 21
      TabOrder = 0
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 135
      Top = 74
      Width = 74
      Height = 21
      TabOrder = 1
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 135
      Top = 114
      Width = 74
      Height = 21
      TabOrder = 2
      OnKeyPress = Edit3KeyPress
    end
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 64
    Width = 308
    Height = 209
    Caption = 'Seleccione el trabajador: '
    TabOrder = 4
    object ListView1: TListView
      Left = 8
      Top = 19
      Width = 290
      Height = 182
      Columns = <
        item
          Caption = 'Nombre y Apellidos'
          Width = 170
        end
        item
          Caption = 'N'#250'mero de Identidad'
          Width = 116
        end>
      GridLines = True
      ReadOnly = True
      RowSelect = True
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object ComboBox1: TComboBox
    Left = 17
    Top = 33
    Width = 308
    Height = 21
    Style = csDropDownList
    TabOrder = 0
    OnChange = ComboBox1Change
  end
  object btnAceptar: TButton
    Left = 376
    Top = 240
    Width = 65
    Height = 25
    Caption = 'Aceptar'
    Enabled = False
    TabOrder = 1
    OnClick = btnAceptarClick
  end
  object btnCancelar: TButton
    Left = 448
    Top = 240
    Width = 65
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = btnCancelarClick
  end
  object btnCerrar: TButton
    Left = 248
    Top = 286
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 3
    OnClick = btnCerrarClick
  end
end
