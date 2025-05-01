### 🔹 01b - Basic UNIX Commands

#### ✦ System Information
```bash
date          # Show date and time
cal           # Calendar
uptime        # How long the system is running
who           # Who is logged in
uname -a      # System details
hostname      # Name of the machine
```

#### ✦ File & Directory Management
```bash
mkdir mydir                # Create a directory
touch file.txt             # Create an empty file
ls                         # List contents
rm file.txt                # Delete file
cp source.txt dest.txt     # Copy file
mv old.txt newdir/         # Move file
chmod 755 script.sh        # Change permissions
```

#### ✦ Text Output & Processing
```bash
echo "Hello, UNIX" > test.txt     # Write text
cat test.txt                      # Show content
grep "word" test.txt              # Search word
head -n 5 test.txt                # First 5 lines
tail -n 5 test.txt                # Last 5 lines
cut -d ':' -f1 /etc/passwd        # Cut column from file
```

#### ✦ Help & Calculator
```bash
man ls        # Manual/help
bc            # Open calculator (type '5+5' to test)
```

#### ✦ Practice Folder Structure
```bash
mkdir -p unix_practice/dir1 unix_practice/dir2
cd unix_practice/dir1
echo "This is file1" > file1.txt
cd ../dir2
echo "This is file2" > file2.txt
```
