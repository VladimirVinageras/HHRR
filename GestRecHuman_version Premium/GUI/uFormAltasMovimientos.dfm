object FormAltasYMov: TFormAltasYMov
  Left = 129
  Top = 138
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Plantilla de Trabajadores - Altas y Movimientos'
  ClientHeight = 382
  ClientWidth = 575
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
  object PageControl1: TPageControl
    Left = 15
    Top = 16
    Width = 543
    Height = 329
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Dar alta'
      object GroupBox1: TGroupBox
        Left = 6
        Top = 8
        Width = 240
        Height = 257
        Caption = 'Departamento de destino'
        TabOrder = 0
        object Label1: TLabel
          Left = 9
          Top = 24
          Width = 135
          Height = 13
          Caption = 'Seleccione el departamento:'
        end
        object Label2: TLabel
          Left = 8
          Top = 238
          Width = 214
          Height = 13
          Caption = #161'Atenci'#243'n!: Se han ocupado todas las plazas.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object ComboBox1: TComboBox
          Left = 9
          Top = 40
          Width = 224
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 0
          OnChange = ComboBox1Change
        end
        object ListView1: TListView
          Left = 8
          Top = 72
          Width = 224
          Height = 177
          Columns = <
            item
              Caption = 'Cargo'
              Width = 117
            end
            item
              Alignment = taCenter
              Caption = 'Plazas Disponibles'
              Width = 103
            end>
          GridLines = True
          ReadOnly = True
          RowSelect = True
          TabOrder = 1
          ViewStyle = vsReport
          OnClick = ListView1Click
        end
      end
      object GroupBox2: TGroupBox
        Left = 254
        Top = 8
        Width = 275
        Height = 257
        Caption = 'Datos del trabajador a ubicar'
        TabOrder = 1
        object Label7: TLabel
          Left = 16
          Top = 24
          Width = 117
          Height = 13
          Caption = 'Seleccione el trabajador:'
        end
        object Label8: TLabel
          Left = 16
          Top = 72
          Width = 100
          Height = 13
          Caption = 'Seleccione el cargo: '
        end
        object ComboBox4: TComboBox
          Left = 16
          Top = 40
          Width = 241
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 0
        end
        object ComboBox5: TComboBox
          Left = 16
          Top = 88
          Width = 241
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 1
        end
        object GroupBox6: TGroupBox
          Left = 9
          Top = 126
          Width = 257
          Height = 115
          Caption = 'En caso de resoluci'#243'n especifique un salario'
          TabOrder = 2
          object Bevel2: TBevel
            Left = 7
            Top = 24
            Width = 241
            Height = 73
            Shape = bsFrame
            Style = bsRaised
          end
          object Label13: TLabel
            Left = 120
            Top = 42
            Width = 104
            Height = 13
            Caption = 'Salario por resoluci'#243'n:'
          end
        end
        object CheckBox1: TCheckBox
          Left = 38
          Top = 184
          Width = 81
          Height = 17
          Caption = 'Resoluci'#243'n'
          TabOrder = 3
          OnClick = CheckBox1Click
        end
        object Edit10: TEdit
          Left = 128
          Top = 183
          Width = 113
          Height = 21
          Color = clBtnFace
          Enabled = False
          TabOrder = 4
          OnKeyPress = Edit10KeyPress
        end
      end
      object btnAceptarAlta: TButton
        Left = 208
        Top = 272
        Width = 67
        Height = 25
        Caption = 'Aceptar'
        Enabled = False
        TabOrder = 2
        OnClick = btnAceptarAltaClick
      end
      object btnCancelarAlta: TButton
        Left = 280
        Top = 272
        Width = 67
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 3
        OnClick = btnCancelarAltaClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Mover a otra plaza'
      ImageIndex = 1
      OnShow = TabSheet2Show
      object GroupBox3: TGroupBox
        Left = 7
        Top = 8
        Width = 275
        Height = 170
        Caption = 'Buscar trabajador'
        TabOrder = 0
        object Label3: TLabel
          Left = 21
          Top = 24
          Width = 101
          Height = 13
          Caption = 'N'#250'mero de identidad:'
        end
        object Edit2: TEdit
          Left = 21
          Top = 40
          Width = 132
          Height = 21
          MaxLength = 11
          TabOrder = 0
          OnKeyPress = Edit2KeyPress
        end
        object bitbtnBuscarTrab: TBitBtn
          Left = 170
          Top = 38
          Width = 75
          Height = 25
          Caption = 'Buscar'
          TabOrder = 1
          OnClick = bitbtnBuscarTrabClick
          Glyph.Data = {
            E6040000424DE604000000000000360000002800000014000000140000000100
            180000000000B0040000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
            0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000800000800000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000800000800000FF000000FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
            00000000FFFFFF0000000000800000800000FF000000FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000808080C0C0C0808080
            0000000000000000800000FF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF000000808080C0C0C0C0C0C0FFFFFFC0C0C0C0C0C080
            8080000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFF000000C0C0C0FFFF00808080808080FFFF00FFFFFFC0C0C00000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
            0000808080C0C0C0FFFFFFC0C0C0FFFF00FFFFFFFFFF00C0C0C0808080000000
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000C0C0
            C0FFFFFFFFFFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00000000000000FFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFF000000C0C0C0808080000000FFFFFF000000FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000C0C0C0FFFFFFFF
            FFFFFFFFFFFFFF00C0C0C0808080000000808080000000FFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080C0C0C0FFFFFFFFFF
            FF000000808080000000808080000000808080000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000808080C0C0C0808080
            000000808080000000808080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000080
            8080808080FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
            00FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF000000FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF}
        end
        object Panel1: TPanel
          Left = 11
          Top = 74
          Width = 251
          Height = 84
          BevelInner = bvLowered
          TabOrder = 2
          object StaticText2: TStaticText
            Left = 57
            Top = 8
            Width = 186
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 0
          end
          object StaticText3: TStaticText
            Left = 8
            Top = 32
            Width = 108
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            Caption = 'Departamento actual:'
            TabOrder = 1
          end
          object StaticText4: TStaticText
            Left = 117
            Top = 32
            Width = 126
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 2
          end
          object StaticText5: TStaticText
            Left = 117
            Top = 56
            Width = 126
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 3
          end
          object StaticText6: TStaticText
            Left = 8
            Top = 56
            Width = 108
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            Caption = 'Cargo que ocupa:'
            TabOrder = 4
          end
        end
        object StaticText1: TStaticText
          Left = 19
          Top = 82
          Width = 48
          Height = 20
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkFlat
          BevelOuter = bvSpace
          BorderStyle = sbsSunken
          Caption = 'Nombre:'
          TabOrder = 3
        end
      end
      object GroupBox4: TGroupBox
        Left = 287
        Top = 8
        Width = 240
        Height = 257
        Caption = 'Departamento de destino'
        TabOrder = 1
        object Label4: TLabel
          Left = 8
          Top = 24
          Width = 135
          Height = 13
          Caption = 'Seleccione el departamento:'
        end
        object Label5: TLabel
          Left = 8
          Top = 238
          Width = 214
          Height = 13
          Caption = #161'Atenci'#243'n!: Se han ocupado todas las plazas.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object ComboBox2: TComboBox
          Left = 8
          Top = 40
          Width = 224
          Height = 21
          Style = csDropDownList
          Enabled = False
          ItemHeight = 13
          TabOrder = 0
          OnChange = ComboBox2Change
        end
        object ListView2: TListView
          Left = 8
          Top = 72
          Width = 224
          Height = 177
          Columns = <
            item
              Caption = 'Cargo'
              Width = 117
            end
            item
              Alignment = taCenter
              Caption = 'Plazas Disponibles'
              Width = 103
            end>
          GridLines = True
          ReadOnly = True
          RowSelect = True
          TabOrder = 1
          ViewStyle = vsReport
        end
      end
      object btnAceptarMover: TButton
        Left = 208
        Top = 272
        Width = 67
        Height = 25
        Caption = 'Aceptar'
        Enabled = False
        TabOrder = 2
        OnClick = btnAceptarMoverClick
      end
      object btnCancelarMover: TButton
        Left = 280
        Top = 272
        Width = 67
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 3
        OnClick = btnCancelarMoverClick
      end
      object GroupBox5: TGroupBox
        Left = 7
        Top = 178
        Width = 275
        Height = 87
        Caption = 'Cargo a ocupar'
        TabOrder = 4
        object Label6: TLabel
          Left = 24
          Top = 24
          Width = 97
          Height = 13
          Caption = 'Seleccione el cargo:'
        end
        object ComboBox3: TComboBox
          Left = 24
          Top = 40
          Width = 224
          Height = 21
          Style = csDropDownList
          Enabled = False
          ItemHeight = 13
          TabOrder = 0
        end
      end
    end
  end
  object btnCerrar: TButton
    Left = 256
    Top = 352
    Width = 73
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = btnCerrarClick
  end
end
