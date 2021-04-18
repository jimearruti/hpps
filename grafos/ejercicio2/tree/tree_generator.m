clear all
close all
home
%%
n=7;


%%
%genera ?rbol balanceado
%type=0;
%genera ?rbol degenerado
type=1;
file_tree=gen_tree(n,type);

%% write file
fname='t.tree';
fid=fopen(fname,'w+');
fprintf(fid,'%d\n',n);
fprintf(fid,'%d\n',n-1);
for i=1:n
    fprintf(fid,'%d\n', file_tree(i));
end
fclose(fid);
