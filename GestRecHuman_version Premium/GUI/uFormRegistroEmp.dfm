object FormRegEmpresa: TFormRegEmpresa
  Left = 212
  Top = 254
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Registros de la Empresa - Entrada de Datos'
  ClientHeight = 360
  ClientWidth = 522
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
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 16
    Top = 16
    Width = 489
    Height = 306
    ActivePage = TabSheet1
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Adicionar Cargos'
      OnShow = TabSheet1Show
      object Bevel2: TBevel
        Left = 8
        Top = 8
        Width = 465
        Height = 259
      end
      object GroupBox1: TGroupBox
        Left = 18
        Top = 24
        Width = 241
        Height = 121
        Caption = 'Inserte el cargo y su salario correspondiente: '
        TabOrder = 0
        object Label1: TLabel
          Left = 16
          Top = 30
          Width = 31
          Height = 13
          Caption = 'Cargo:'
        end
        object Label2: TLabel
          Left = 16
          Top = 62
          Width = 35
          Height = 13
          Caption = 'Salario:'
        end
        object Edit1: TEdit
          Left = 56
          Top = 30
          Width = 97
          Height = 21
          Color = clBtnFace
          TabOrder = 0
          OnKeyPress = Edit1KeyPress
        end
        object Edit2: TEdit
          Left = 56
          Top = 62
          Width = 97
          Height = 21
          Color = clBtnFace
          MaxLength = 15
          TabOrder = 1
          OnKeyPress = Edit2KeyPress
        end
        object btnAdicionarCargos: TButton
          Left = 160
          Top = 86
          Width = 67
          Height = 25
          Caption = 'Adicionar'
          TabOrder = 2
          OnClick = btnAdicionarCargosClick
        end
      end
      object ListView1: TListView
        Left = 266
        Top = 28
        Width = 197
        Height = 230
        Columns = <
          item
            Caption = 'Cargo'
            Width = 131
          end
          item
            Alignment = taCenter
            Caption = 'Salario'
            Width = 62
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 1
        ViewStyle = vsReport
      end
      object GroupBox2: TGroupBox
        Left = 18
        Top = 153
        Width = 241
        Height = 105
        Caption = 'Cargo de Jefe de Departamento'
        TabOrder = 2
        object Label7: TLabel
          Left = 16
          Top = 36
          Width = 79
          Height = 13
          Caption = 'Inserte el salario:'
        end
        object Edit10: TEdit
          Left = 102
          Top = 36
          Width = 97
          Height = 21
          MaxLength = 15
          TabOrder = 0
          OnKeyPress = Edit10KeyPress
        end
        object btnCargoJefeDpto: TButton
          Left = 160
          Top = 69
          Width = 67
          Height = 25
          Caption = 'Adicionar'
          TabOrder = 1
          OnClick = btnCargoJefeDptoClick
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Adicionar Trabajadores'
      ImageIndex = 1
      OnEnter = TabSheet2Enter
      object Panel1: TPanel
        Left = 7
        Top = 8
        Width = 282
        Height = 156
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 2
        object Label3: TLabel
          Left = 8
          Top = 8
          Width = 93
          Height = 13
          Caption = 'Nombre y Apellidos:'
        end
        object Label4: TLabel
          Left = 8
          Top = 56
          Width = 101
          Height = 13
          Caption = 'Numero de identidad:'
        end
        object Label5: TLabel
          Left = 8
          Top = 104
          Width = 94
          Height = 13
          Caption = 'Direccion particular:'
        end
        object Label6: TLabel
          Left = 144
          Top = 56
          Width = 45
          Height = 13
          Caption = 'Telefono:'
        end
        object Edit3: TEdit
          Left = 8
          Top = 24
          Width = 265
          Height = 21
          TabOrder = 0
          OnKeyPress = Edit3KeyPress
        end
        object Edit4: TEdit
          Left = 8
          Top = 72
          Width = 129
          Height = 21
          MaxLength = 11
          TabOrder = 1
          OnKeyPress = Edit4KeyPress
        end
        object Edit6: TEdit
          Left = 144
          Top = 72
          Width = 129
          Height = 21
          MaxLength = 12
          TabOrder = 2
          OnKeyPress = Edit6KeyPress
        end
        object Edit5: TEdit
          Left = 8
          Top = 121
          Width = 265
          Height = 21
          TabOrder = 3
        end
      end
      object btnAdicionarTrab: TButton
        Left = 71
        Top = 171
        Width = 74
        Height = 25
        Caption = 'Adicionar'
        TabOrder = 0
        OnClick = btnAdicionarTrabClick
      end
      object btnCancelarTrab: TButton
        Left = 151
        Top = 171
        Width = 74
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 1
        OnClick = btnCancelarTrabClick
      end
      object ListView2: TListView
        Left = 296
        Top = 8
        Width = 177
        Height = 262
        Columns = <
          item
            Caption = 'Trabajadores'
            Width = 173
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 3
        ViewStyle = vsReport
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Adicionar Departamentos'
      ImageIndex = 2
      OnShow = TabSheet3Show
      object Label8: TLabel
        Left = 24
        Top = 24
        Width = 40
        Height = 13
        Caption = 'Nombre:'
      end
      object Label9: TLabel
        Left = 151
        Top = 24
        Width = 36
        Height = 13
        Caption = 'Codigo:'
      end
      object Bevel1: TBevel
        Left = 8
        Top = 8
        Width = 465
        Height = 233
      end
      object Edit8: TEdit
        Left = 151
        Top = 40
        Width = 120
        Height = 21
        MaxLength = 15
        TabOrder = 1
      end
      object Edit7: TEdit
        Left = 24
        Top = 40
        Width = 120
        Height = 21
        TabOrder = 0
        OnKeyPress = Edit7KeyPress
      end
      object GroupBox3: TGroupBox
        Left = 24
        Top = 72
        Width = 247
        Height = 153
        Caption = 'Inserte cargos y sus plazas aprobadas: '
        TabOrder = 2
        object Label10: TLabel
          Left = 14
          Top = 21
          Width = 31
          Height = 13
          Caption = 'Cargo:'
        end
        object Label11: TLabel
          Left = 14
          Top = 78
          Width = 87
          Height = 13
          Caption = 'Plazas aprobadas:'
        end
        object ComboBox1: TComboBox
          Left = 14
          Top = 37
          Width = 217
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 0
          OnChange = ComboBox1Change
        end
        object Edit9: TEdit
          Left = 107
          Top = 77
          Width = 122
          Height = 21
          MaxLength = 4
          TabOrder = 1
          OnKeyPress = Edit9KeyPress
        end
        object btnCargoPlazas: TButton
          Left = 162
          Top = 115
          Width = 71
          Height = 26
          Caption = 'Insertar'
          TabOrder = 2
          OnClick = btnCargoPlazasClick
        end
      end
      object btnAdicionarDep: TButton
        Left = 165
        Top = 248
        Width = 75
        Height = 25
        Caption = 'Adicionar'
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = btnAdicionarDepClick
      end
      object btnCancelarDep: TButton
        Left = 245
        Top = 248
        Width = 75
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 4
        OnClick = btnCancelarDepClick
      end
      object ListView3: TListView
        Left = 280
        Top = 24
        Width = 177
        Height = 201
        Columns = <
          item
            Caption = 'Departamentos'
            Width = 173
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 5
        ViewStyle = vsReport
      end
    end
  end
  object btnCerrar: TButton
    Left = 224
    Top = 329
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = btnCerrarClick
  end
end
