object FormPlazasMenosCubiertas: TFormPlazasMenosCubiertas
  Left = 122
  Top = 134
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Listado de las Plazas Menos Cubiertas'
  ClientHeight = 456
  ClientWidth = 569
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
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 553
    Height = 409
  end
  object Panel1: TPanel
    Left = 20
    Top = 16
    Width = 529
    Height = 48
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 4
    object Label1: TLabel
      Left = 15
      Top = 16
      Width = 172
      Height = 13
      Caption = 'Cantidad de cargos que desea listar:'
    end
    object btnMostarTodos: TButton
      Left = 423
      Top = 12
      Width = 94
      Height = 25
      Caption = 'Mostrar Todos'
      TabOrder = 0
      OnClick = btnMostarTodosClick
    end
  end
  object ListView1: TListView
    Left = 19
    Top = 74
    Width = 529
    Height = 331
    Columns = <
      item
        Caption = 'Cargo'
        Width = 110
      end
      item
        Caption = 'Porciento Ocupado'
        Width = 113
      end
      item
        Caption = 'Salario'
        Width = 57
      end
      item
        Caption = 'Departamento'
        Width = 115
      end
      item
        Caption = 'Jefe de Departamento'
        Width = 130
      end>
    GridLines = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
  end
  object btnCerrar: TButton
    Left = 247
    Top = 425
    Width = 75
    Height = 24
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = btnCerrarClick
  end
  object btnMostrar: TButton
    Left = 326
    Top = 28
    Width = 81
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 2
    OnClick = btnMostrarClick
  end
  object CSpinEdit1: TCSpinEdit
    Left = 212
    Top = 29
    Width = 105
    Height = 22
    MaxValue = 999999
    TabOrder = 3
    OnChange = CSpinEdit1Change
    OnKeyPress = CSpinEdit1KeyPress
  end
end
