function file_tree=gen_tree(n,type)

if(type==0)
H=ceil(log(n)/log(2));
else
H=ceil(n/2);
end
file_tree=zeros(1,n);

n_h_acc=0;
for h=1:H
    if(type==0)
        n_h=ceil(n/2^h);
    else
        if(h~=H)
            n_h=2;
        else
            n_h=1;
        end
    end
    fprintf('h: %d n_h: %d\n',h,n_h);
    
    for i=0:n_h-1
        ind=n_h_acc+i;
        if(ind~=n-1)
            p_i=n_h_acc+n_h+floor(i/2);
        else
            p_i=-1;
        end
        fprintf('i: %d ind: %d p: %d\n',i,ind,p_i);
        file_tree(ind+1)=p_i;
    end
    
    n_h_acc=n_h_acc+n_h;
end