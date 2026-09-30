import os
import zipfile
import argparse

class VShell:
    def __init__(self, zip_file):
        self.zip_file = zip_file
        self.current_dir = ''
    
    def execute_command(self, command):
        if command == 'pwd':
            print(self.current_dir)
        elif command == 'ls':
            with zipfile.ZipFile(self.zip_file, 'r') as zip_ref:
                file_list = zip_ref.namelist()
##                print(file_list)
                out=[]
                for file in file_list:
                    if 1!=file.startswith(self.current_dir):
                        continue
                    try:
                        
                        file=file.replace(self.current_dir, '')
                        file=file[:file.index('/')]
                        #print(file)
                        
                        if  file != '' and file not in out:
                            print(file)
                            out.append(file)
                    except:
                        try:
                            file=file.replace(self.current_dir, '')
                        
                            #print(file)
                            if file != '' and file not in out:
                                print(file)
                                out.append(file)
                        except:
                            1
        elif command.startswith('cd'):
            try:
                new_dir = command.split(' ')[1]
            except:
                self.current_dir=''
                return
            if new_dir == '..':
                self.current_dir = os.path.dirname(self.current_dir)
            else:
                new_dir = os.path.join(self.current_dir, new_dir)
##                print(new_dir)
                with zipfile.ZipFile(self.zip_file, 'r') as zip_ref:
                    file_list = zip_ref.namelist()
                    #print(file_list)
                    for file in file_list:
                        if file.startswith(new_dir + '/'):
                            self.current_dir = new_dir + '/'
##                            print(self.current_dir)
                            return
                        
                    print('Directory not found')
        elif command.startswith('cat'):
            file_name = command.split(' ')[1]
            with zipfile.ZipFile(self.zip_file, 'r') as zip_ref:
                file_list = zip_ref.namelist()
                if self.current_dir + file_name in file_list:
                    with zip_ref.open(self.current_dir + file_name, 'r') as file:
                        print(file.read().decode('utf-8'))
                else:
                    print('File not found')
        else:
            print('Command not found')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='VShell emulator')
    parser.add_argument('--script', help='Execute commands from a script file')

    args = parser.parse_args()
    zip_file = '_браузер и интернет.zip' 
    vshell = VShell(zip_file)
   
##    while True:
##        command = input('$ ')
##        if command == 'exit':
##            break
##        vshell.execute_command(command)
    if args.script:
        with open(args.script, 'r') as file:
            commands = file.readlines()
            for command in commands:
                vshell.execute_command(command.strip())
    else:
        while True:
            command = input('$ ')
            if command == 'exit':
                break
            vshell.execute_command(command)
