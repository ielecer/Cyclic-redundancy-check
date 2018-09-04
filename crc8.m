% Input values.
Input = [0, 0, 1, 1, 0, 0, 0, 0, ...    % '0'
         0, 0, 1, 1, 0, 0, 0, 1, ...    % '1'
         0, 0, 1, 1, 0, 0, 1, 0];       % '2'
     
% Add 8 zeros behind input data.
z = zeros(1, 8);
M1 = [Input, z];

% Generating polynomial
G1 = [1, 0, 0, 1, 1, 0, 0, 0, 1];

mL = length(M1);
gL = length(G1);
count = 0;
while((mL - count) >= gL)
    % "A xor B" or "(A + B) mod 2".
    msg9 = M1(1:gL);
    rem = mod((msg9 + G1), 2);
    M1(1:gL) = rem;
    
    % Remove the intial zeros.
    j = 1;
    shft = 0;
    while(j <= gL)
        if(rem(j) ~= 0) % “～=“：not equal.
            break;
        else
            shft = j;
            j = j + 1;
        end
    end
    count = count + shft;
    M1(1 : shft) = [];
end

% convert binary to decimal
j = 0;
value = 0;
chksuml = length(M1);
for j = 1 : chksuml
    if (M1(j) == 1)
        value = value + (2 ^ (chksuml - j));
    end
end

dec2hex(value) % decimal to hex CRC8 output