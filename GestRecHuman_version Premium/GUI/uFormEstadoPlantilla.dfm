object FormEstadoPlantilla: TFormEstadoPlantilla
  Left = 163
  Top = 179
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Plantilla de Trabajadores - Estado de la Plantilla'
  ClientHeight = 350
  ClientWidth = 511
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
  DesignSize = (
    511
    350)
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 13
    Top = 13
    Width = 485
    Height = 298
  end
  object Label1: TLabel
    Left = 220
    Top = 32
    Width = 141
    Height = 13
    AutoSize = False
    Caption = 'Seleccione el departamento: '
  end
  object RadioGroup1: TRadioGroup
    Left = 27
    Top = 30
    Width = 181
    Height = 81
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'Estado actual de la empresa'
    DragMode = dmAutomatic
    Items.Strings = (
      'Total'
      'Por departamentos')
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object ComboBox1: TComboBox
    Left = 220
    Top = 49
    Width = 222
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 1
    OnChange = ComboBox1Change
  end
  object ListView1: TListView
    Left = 27
    Top = 125
    Width = 458
    Height = 172
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelInner = bvLowered
    BevelOuter = bvRaised
    Color = clHighlightText
    Columns = <
      item
        Caption = 'Cargo'
        Width = 135
      end
      item
        Alignment = taCenter
        Caption = 'Plazas Aprobadas'
        Width = 100
      end
      item
        Alignment = taCenter
        Caption = 'Plazas Ocupadas'
        Width = 100
      end
      item
        Alignment = taCenter
        Caption = 'Por ciento Completado'
        Width = 122
      end>
    Ctl3D = False
    DragMode = dmAutomatic
    FlatScrollBars = True
    FullDrag = True
    GridLines = True
    ReadOnly = True
    RowSelect = True
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
    ViewStyle = vsReport
  end
  object Panel1: TPanel
    Left = 220
    Top = 79
    Width = 222
    Height = 32
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    Visible = False
    object StaticText1: TStaticText
      Left = 5
      Top = 6
      Width = 157
      Height = 20
      AutoSize = False
      BevelInner = bvSpace
      BevelKind = bkFlat
      BevelOuter = bvSpace
      BorderStyle = sbsSunken
      Caption = 'Por ciento general completado:'
      TabOrder = 0
    end
    object StaticText2: TStaticText
      Left = 163
      Top = 6
      Width = 53
      Height = 20
      Alignment = taCenter
      AutoSize = False
      BevelInner = bvSpace
      BevelKind = bkFlat
      BevelOuter = bvSpace
      BorderStyle = sbsSunken
      TabOrder = 1
    end
  end
  object btnCerrar: TButton
    Left = 216
    Top = 319
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 4
    OnClick = btnCerrarClick
  end
end
