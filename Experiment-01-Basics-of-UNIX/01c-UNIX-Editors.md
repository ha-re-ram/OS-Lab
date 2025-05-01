### 🔹 01c - UNIX Editors

#### ✦ vi Editor Basics
```bash
vi file.txt
# Press 'i' to insert text
# Press 'Esc' to enter command mode
# :w     -> Save file
# :q     -> Quit
# :wq    -> Save and quit
# :s/old/new/g -> Replace all 'old' with 'new'
```

#### ✦ ed Editor
```bash
ed sample.txt
a
This is line 1.
.
w
q
# Commands:
# a (append), d (delete), w (write/save), q (quit)
```

#### ✦ ex Editor
```bash
ex sample.txt
# Similar to ed
# Use : commands like :a, :wq, :s/word/new
```

#### ✦ emacs Editor
```bash
emacs file.txt
# Ctrl + x, Ctrl + s : Save
# Ctrl + x, Ctrl + c : Quit
# M-x replace-string : Search & replace
```

#### ✦ Editor Comparison Table

| Editor | Interface | Use Case | Learning Curve |
|--------|-----------|----------|----------------|
| vi     | CLI       | Fast edits | Medium         |
| ed     | CLI       | Simple edits | High         |
| ex     | CLI       | Scripting | Medium         |
| emacs  | CLI/GUI   | Advanced usage | High        |
